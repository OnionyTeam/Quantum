#include "editor.h"
#include "editor_helpers.h"
#include "command/command.h"
#include <experimental/filesystem>
#include <cassert>
#include <fstream>

Editor::Editor(const std::string &filename, bool active, const WindowInfo &info)
    : View(info)
{
    _active = active;
    _editor_info.filename = filename;
    _cursor_info = {0};
    _editor_info.refresh_all = true;
    _editor_info.modified = false;

    load_file();
    init();
}

Editor::Editor(const EditorInfo &editor_info, const WindowInfo &window_info)
    : View(window_info), _editor_info(editor_info)
{
    load_file();
    init();
}

void Editor::init()
{
    WINDOW *window = _window.get();
    _last_cursor_x = _cursor_info.x;
    wmove(window, _cursor_info.y,
          _cursor_info.x);
}
void Editor::open_file(const std::wstring &filename)
{
    // TODO
}
void Editor::update_buffer()
{
    // just update the area which changed
    WINDOW *window = _window.get();
    // first, clear the window
    werase(window);
    auto line_num = static_cast<int>(_current_buffer->lines.size());
    auto lines = std::min(config::ncurses_info.lines, line_num);
    for (int i = 0; i < lines; ++i)
    {
        // print the buffer
        mvwaddwstr(window, i, 0,
                   _current_buffer->lines[_scroll_y + i].c_str() + _scroll_x);
    }
    if (_active) // local pos
        wmove(window, _cursor_info.y - _scroll_y, wcswidth(_current_buffer->lines[_cursor_info.y].c_str(), _cursor_info.x - _scroll_x));
    wrefresh(window);
}

void Editor::update()
{
    if (_editor_info.refresh_all || _editor_info.modified)
    {
        update_buffer();
        _editor_info.refresh_all = false;
    }
}

void Editor::save_file()
{
    if (_editor_info.filename.empty())
        _editor_info.filename = "untitled";

    std::wofstream f(_editor_info.filename);
    if (f.is_open())
    {
        for (size_t i = 0; i < _current_buffer->lines.size(); i++)
        {
            f << _current_buffer->lines[i] << std::endl;
        }
    }

    f.close();
}

void Editor::load_file()
{
    std::wifstream infile(_editor_info.filename);
    if (!infile)
    {
        // file does not exist
        _current_buffer->append_line(L"");
        _editor_info.new_file = true;
    }
    else
    {
        std::wstring temp;
        int i = 0;
        while (!std::getline(infile, temp).eof())
        {
            _current_buffer->append_line(temp);
            i++;
        }
        _editor_info.new_file = false;
    }
}

void Editor::type_char(wchar_t c)
{
    if (!_editor_info.read_only)
    {
        std::wstring &current_line = _current_buffer->lines[_cursor_info.y];
        current_line.insert(current_line.begin() + _cursor_info.x, c);
        _cursor_info.x++;
        _editor_info.modified = true;
    }
}

void Editor::key_input_event(wint_t key)
{
    try
    {
        command_map.at(key_map.at(key))(this);
        _editor_info.modified = true;
    }
    catch (...)
    {
        type_char(key);
    }
}

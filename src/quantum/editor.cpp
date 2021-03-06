#include "editor.h"
#include "editor_helpers.h"
#include "command/command.h"
#include "components/status_line.h"
#include "window.h"
#include <experimental/filesystem>
#include <cassert>
#include <fstream>

Editor::Editor(const std::string &filename, const WindowInfo &info, std::shared_ptr<Window> parent, bool active)
    : View(info, parent)
{
    _active = active;
    _editor_info.filename = filename;
    _editor_info.refresh_all = true;
    _editor_info.modified = false;

    load_file();
    init();
}

Editor::Editor(const EditorInfo &editor_info, const WindowInfo &window_info, std::shared_ptr<Window> parent)
    : View(window_info, parent), _editor_info(editor_info)
{
    load_file();
    init();
}

void Editor::init()
{
    _last_cursor_x = _cursor_info.x;
    update_cursor();
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
    auto line_num = static_cast<unsigned int>(_current_buffer->lines.size());
    auto lines = std::min(_window_info.lines, line_num);
    for (unsigned int i = 0; i < lines; ++i)
    {
        // print the buffer
        mvwaddwstr(window, i, _window_info.x,
                   _current_buffer->lines[_scroll_y + i].c_str() + _scroll_x);
    }
    if (_active) // local pos
        update_cursor();
}

void Editor::update_cursor()
{
    int y_pos = 0;
    for (auto &&a : _current_buffer->lines)
    {
        size_t len  = a.size();
        while (len > 0)
        {
            len -= _window_info.cols;
            y_pos++;
        }
    }
    wmove(_window.get(), y_pos - _scroll_y, 
        wcswidth(_current_buffer->lines[_cursor_info.y].c_str(), _cursor_info.x - _scroll_x));
}
void Editor::update()
{
    if (_editor_info.refresh_all || _editor_info.modified)
    {
        update_buffer();
        if (_active) wrefresh(_window.get());
        else
            wnoutrefresh(_window.get());
        _editor_info.refresh_all = false;
    }
    // wrefresh(_window.get());
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
        while (!std::getline(infile, temp).eof())
        {
            _current_buffer->append_line(temp);
        }
        _current_buffer->append_line(L"");
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
    if (key_map.count(key) == 1)
    {
        try
        {
            command_map.at(key_map.at(key))(this);
        }
        catch (...)
        {
        }
    }
    else
    {
        type_char(key);
        _parent->get_status_line()->show_message(std::to_wstring(key));
    }
}

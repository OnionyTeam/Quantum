#include "editor.h"
#include "editor_helpers.h"
#include <cassert>
#include <fstream>

Editor::Editor(const std::string &filename, bool active, const WindowInfo &info)
    : View(info), _active(active)
{
    _editor_info.filename = filename;
    _editor_info.cursor_info = {0};
    _editor_info.refresh_all = true;

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
    wmove(window, _editor_info.cursor_info.x,
          _editor_info.cursor_info.y);
    // curs_set(0);
}
void Editor::open_file(const std::string &filename)
{
    // TODO
}
void Editor::update_buffer()
{
    // just update the area which changed
    WINDOW *window = _window.get();
    assert(window != nullptr);
    if (_editor_info.refresh_all)
    {
        // first, clear the window
        // wclear(window);
        // wrefresh(window);
        auto line_num = static_cast<int>(_current_buffer->lines.size());
        for (int i = 0; i < line_num; ++i)
        {
            // print the buffer
            mvwaddstr(window, i, 0,
                      _current_buffer->lines[i].c_str());
        }
        // wmove(window, static_cast<int>(_current_buffer->lines.back().size()), _current_buffer->lines.size());
        if (_active)
            wmove(window, _editor_info.cursor_info.x, _editor_info.cursor_info.y);
        wrefresh(window);
        _editor_info.refresh_all = false;
    }
    // else 
    // {
    //     while (!_changed_lines.empty())
    //     {
    //         auto line_num = _changed_lines.top();
    //         mvwaddstr(_window.get(), line_num, 0, _current_buffer->lines[line_num].c_str());
    //         _changed_lines.pop();
    //     }
    // }
}

void Editor::update()
{
    update_buffer();
}

void Editor::load_file()
{
    std::ifstream infile(_editor_info.filename);
    if (!infile)
    {
        //TODO
    }
    else
    {
        std::string temp;
        int i = 0;
        while (!std::getline(infile, temp).eof())
        {
            _current_buffer->append_line(temp);
            // _changed_lines.push(i);
            i++;
        }
    }
}

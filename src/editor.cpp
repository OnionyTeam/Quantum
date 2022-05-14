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
        //wclear(window);
        auto line_num = static_cast<int>(_current_buffer->lines.size());
        for (int i = 0; i < line_num; ++i)
        {
            // print the buffer
            mvwaddstr(window, i, 0,
                      _current_buffer->lines[i].c_str());
        }
        if (_active)
            wmove(window, _editor_info.cursor_info.x, _editor_info.cursor_info.y);
        wrefresh(window);
        _editor_info.refresh_all = false;
    }
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
        //file does not exist
        _current_buffer->append_line("");
        _editor_info.new_file = true;
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
        _editor_info.new_file = false;
    }
}

void Editor::key_input_event(int key)
{
    _current_buffer->append_line(std::to_string(key));
    _editor_info.refresh_all = true;
}

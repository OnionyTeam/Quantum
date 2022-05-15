#include "editor.h"
#include "editor_helpers.h"
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
void Editor::open_file(const std::string &filename)
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
    for (int i = 0; i < line_num; ++i)
    {
        // print the buffer
        mvwaddstr(window, i, 0,
                    _current_buffer->lines[i].c_str());
    }
    if (_active)
        wmove(window, _cursor_info.y, _cursor_info.x);
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

void Editor::load_file()
{
    std::ifstream infile(_editor_info.filename);
    if (!infile)
    {
        // file does not exist
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
            i++;
        }
        _editor_info.new_file = false;
    }
}

void Editor::type_char(char c)
{
    if (!_editor_info.read_only)
    {
        std::string &current_line = _current_buffer->lines[_cursor_info.y];
        current_line.insert(current_line.begin() + _cursor_info.x, c);
        _cursor_info.x++;
        _editor_info.modified = true;
    }
}

void Editor::key_input_event(int key)
{
    switch (key)
    {
    case KEY_LEFT:
        this->move_left();
        break;
    case KEY_RIGHT:
        this->move_right();
        break;
    case KEY_DOWN:
        this->move_down();
        break;
    case KEY_UP:
        this->move_up();
        break;
    case KEY_BACKSPACE: //有问题、、
    {

        if (_cursor_info.x == 0 && _cursor_info.y == 0) // no charactor could delete
            break;
        else if (_cursor_info.x == 0 && _cursor_info.y >= 0)
        {
            int y = _cursor_info.y;
            int res_pos = _current_buffer->lines[y-1].size();
            if (_current_buffer->lines[y].empty())
            {
                _cursor_info.x = _current_buffer->lines[y - 1].size();
                _current_buffer->remove_line(y);
            }
            else
            {
                //合并两行内容
                _current_buffer->lines[y-1].append(_current_buffer->lines[y]);
                _current_buffer->remove_line(y);
            }
            _cursor_info.x = res_pos;
            this->move_up();
            _editor_info.modified = true;
        }
        else
        {
            int y = _cursor_info.y;
            _current_buffer->lines[y].
                    erase(_cursor_info.x-1, 1);
            _cursor_info.x--;
            _editor_info.modified = true;
            
        }
        break;
    }
    case '\n':
    {
        auto y = _cursor_info.y;
        auto x = _cursor_info.x;
        auto size = _current_buffer->lines[y].size();
        if (x == size)
        {
            if (_current_buffer->lines.size() > _cursor_info.y)
                _current_buffer->insert_line("", y + 1);
            else
                _current_buffer->append_line("");
        }
        else
        {
            if (_current_buffer->lines.size() > _cursor_info.y)
                _current_buffer->insert_line("", y + 1);
            else
                _current_buffer->append_line("");

            y = _cursor_info.y;
            _current_buffer->lines[y+1].append(_current_buffer->lines[y].substr(x));
            _current_buffer->lines[y].erase(x);
        }
        _cursor_info.y++;
        _cursor_info.x = 0;
        _editor_info.modified = true;
        break;
    }
    default:
        type_char(key);
    }
}

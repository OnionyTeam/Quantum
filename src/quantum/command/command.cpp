#include "command.h"

void Command::move_up(Editor *e) { e->move_up(); }

void Command::move_down(Editor *e) { e->move_down(); }

void Command::move_left(Editor *e) { e->move_left(); }

void Command::move_right(Editor *e) { e->move_right(); }

void Command::page_up(Editor *e) { e->scroll_up(); }

void Command::page_down(Editor *e) { e->scroll_down(); }

void Command::save(Editor *e) { e->save_file(); };

void Command::backspace(Editor *e)
{
    if (e->_cursor_info.x == 0 && e->_cursor_info.y == 0) // no charactor could delete
        return;
    else if (e->_cursor_info.x == 0 && e->_cursor_info.y >= 0)
    {
        int y = e->_cursor_info.y;
        int res_pos = e->_current_buffer->lines[y - 1].size();
        if (e->_current_buffer->lines[y].empty())
        {
            e->_cursor_info.x = e->_current_buffer->lines[y - 1].size();
            e->_current_buffer->remove_line(y);
        }
        else
        {
            //合并两行内容
            e->_current_buffer->lines[y - 1].append(e->_current_buffer->lines[y]);
            e->_current_buffer->remove_line(y);
        }
        e->_cursor_info.x = res_pos;
        e->move_up();
        e->_editor_info.modified = true;
    }
    else
    {
        int y = e->_cursor_info.y;
        e->_current_buffer->lines[y].erase(e->_cursor_info.x - 1, 1);
        e->_cursor_info.x--;
        e->_editor_info.modified = true;
    }
}

void Command::enter(Editor *e)
{
    auto y = e->_cursor_info.y;
    auto x = e->_cursor_info.x;
    auto size = e->_current_buffer->lines[y].size();
    if (x == size) //若光标在行末
    {
        if (e->_current_buffer->lines.size() > e->_cursor_info.y)
            e->_current_buffer->insert_line(L"", y + 1);
        else
            e->_current_buffer->append_line(L"");
    }
    else
    {
        if (e->_current_buffer->lines.size() > e->_cursor_info.y)
            e->_current_buffer->insert_line(L"", y + 1);
        else
            e->_current_buffer->append_line(L"");

        y = e->_cursor_info.y;
        e->_current_buffer->lines[y + 1].append(e->_current_buffer->lines[y].substr(x));
        e->_current_buffer->lines[y].erase(x);
    }
    e->_cursor_info.y++;
    e->_cursor_info.x = 0;
    e->_editor_info.modified = true;
    if (e->_cursor_info.y - e->_scroll_y >= e->_window_info.lines)
        e->scroll_down();
}
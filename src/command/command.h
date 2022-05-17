#ifndef _QUANTUM_COMMAND_H__
#define _QUANTUM_COMMAND_H__

#include "../editor.h"
#include <functional>
#include <map>

struct Command
{
    enum class Edit
    {
        MoveUp,
        MoveDown,
        MoveLeft,
        MoveRight,
        PageUp,
        PageDown,
        Backspace,
        Enter,
        Save
    };
    static void move_up(Editor *e) { e->move_up(); }
    static void move_down(Editor *e) { e->move_down(); }
    static void move_left(Editor *e) { e->move_left(); }
    static void move_right(Editor *e) { e->move_right(); }
    static void page_up(Editor *e) { e->scroll_up(); }
    static void page_down(Editor *e) { e->scroll_down(); }
    static void save(Editor *e) { e->save_file(); }
    static void backspace(Editor *e)
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
    static void enter(Editor *e)
    {
        auto y = e->_cursor_info.y;
        auto x = e->_cursor_info.x;
        auto size = e->_current_buffer->lines[y].size();
        if (x == size)  //若光标在行末
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
            e->_current_buffer->lines[y+1].append(e->_current_buffer->lines[y].substr(x));
            e->_current_buffer->lines[y].erase(x);
        }
        e->_cursor_info.y++;
        e->_cursor_info.x = 0;
        e->_editor_info.modified = true;
        if (e->_cursor_info.y - e->_scroll_y >= static_cast<unsigned int>(config::ncurses_info.lines)) e->scroll_down();
    }
};

const static std::map<int, Command::Edit> key_map{
    {KEY_LEFT, Command::Edit::MoveLeft},
    {KEY_RIGHT, Command::Edit::MoveRight},
    {KEY_UP, Command::Edit::MoveUp},
    {KEY_DOWN, Command::Edit::MoveDown},
    {KEY_PPAGE, Command::Edit::PageUp},
    {KEY_NPAGE, Command::Edit::PageDown},
    {KEY_BACKSPACE, Command::Edit::Backspace},
    {10, Command::Edit::Enter},
    {KEY_ENTER, Command::Edit::Enter},
    {KEY_F(2), Command::Edit::Save}
};

const static std::map<Command::Edit, std::function<void(Editor *)>> command_map{
    {Command::Edit::MoveUp, Command::move_up},
    {Command::Edit::MoveDown, Command::move_down},
    {Command::Edit::MoveLeft, Command::move_left},
    {Command::Edit::MoveRight, Command::move_right},
    {Command::Edit::PageUp, Command::page_up},
    {Command::Edit::PageDown, Command::page_down},
    {Command::Edit::Backspace, Command::backspace},
    {Command::Edit::Enter, Command::enter},
    {Command::Edit::Save, Command::save}
};

#endif //_QUANTUM_COMMAND_H__
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
    static void move_up(Editor *e);
    static void move_down(Editor *e);
    static void move_left(Editor *e);
    static void move_right(Editor *e);
    static void page_up(Editor *e);
    static void page_down(Editor *e);
    static void save(Editor *e);
    static void backspace(Editor *e);
    static void enter(Editor *e);
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
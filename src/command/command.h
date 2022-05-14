#ifndef _QUANTUM_COMMAND_H__
#define _QUANTUM_COMMAND_H__

#include "../editor.h"

struct Command
{
    static void cursor_move_up(Editor *e)
    {
        e->_editor_info.cursor_info.y++;
    }

    static void cursor_move_down(Editor *e)
    {
        e->_editor_info.cursor_info.y--;
    }

    static void cursor_move_left(Editor *e)
    {
        e->_editor_info.cursor_info.x--;
    }

    static void cursor_move_right(Editor *e)
    {
        e->_editor_info.cursor_info.x++;
    }
};


#endif //_QUANTUM_COMMAND_H__
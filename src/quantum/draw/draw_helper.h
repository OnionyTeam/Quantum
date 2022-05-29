#ifndef _QUANTUM_DRAW_HELPER_H__
#define _QUANTUM_DRAW_HELPER_H__

#include <ncursesw/ncurses.h>
#include "../global_config.h"

enum class Align
{
    LeftAlign,
    RightAligh,
    Center
};

namespace draw
{
    void draw_text_with_align(WINDOW* w, const config::char_type* c, unsigned int y, Align align);
} // namespace draw


#endif //_QUANTUM_DRAW_HELPER_H__
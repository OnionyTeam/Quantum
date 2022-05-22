#ifndef _QUANTUM_DRAW_HELPER_H__
#define _QUANTUM_DRAW_HELPER_H__

#include <ncursesw/ncurses.h>

enum class Align
{
    LeftAlign,
    RightAligh,
    Center
};

namespace draw
{
    typedef wchar_t char_type;
    void draw_text_with_align(WINDOW* w, const char_type* c, unsigned int y, Align align);
} // namespace draw


#endif //_QUANTUM_DRAW_HELPER_H__
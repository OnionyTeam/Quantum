#include "draw_helper.h"
#include "../global_config.h"

namespace draw
{
    void draw_text_with_align(WINDOW* w, const config::char_type* c, unsigned int y, Align align)
    {
        unsigned int pos = 0, row, col;
        size_t len = wcslen(c);
        getmaxyx(w, row, col);
        switch (align)
        {
        case Align::RightAligh:
            pos = col - len;   
            break;
        case Align::Center:
            pos = (col - len) / 2; 
        default:
            break;
        }
        mvwaddwstr(w, y, pos, c);   
    }
}
    

#include <ncurses.h>

#define ctrl(x)           ((x) & 0x1f)

void init_ncurses()
{
    // init ncurses screen, making main window too
    initscr();
    // change how terminal input works
    // initialise colours
    start_color();
    // don't echo typed characters back
    noecho();
    // characters read 1 by 1
    cbreak();
    // get all keys
    keypad(stdscr, true);
}
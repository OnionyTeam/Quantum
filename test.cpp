#include <ncurses.h>
#include <iostream>
#include <spdlog/spdlog.h>

int main()
{
    initscr();
    start_color();
    refresh();
    WINDOW* win = newwin(0,0,0,0);
    mvwprintw(win, 0, 0, "HELLO, WORLD!");
    wrefresh(win);
//    refresh();
    getch();
    delwin(win);
    endwin();
}

#include <ncurses.h>
#include <iostream>

int main()
{
    initscr();
    start_color();
    refresh();
    WINDOW* win = newwin(0,0,0,0);
    mvwprintw(win, 5, 5, "HELLO, WORLD!");
    wrefresh(win);
    refresh();
    getch();
    delwin(win);
    endwin();
}

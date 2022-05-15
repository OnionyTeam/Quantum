#include <ncurses.h>
#include <iostream>
#include <spdlog/spdlog.h>

int main()
{
    initscr();
    start_color();
    cbreak();
    noecho();
    int a = getch();
    int b = getch();
    int c = getch();
    printw("%d %d %d", a, b, c);
    getch();
    endwin();
}

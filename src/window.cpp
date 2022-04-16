#include "window.h"
#include <iostream>
#include <ncurses.h>

Window::Window()
    : win(std::shared_ptr<WINDOW>(newwin(0, 0, 0, 0)))   // full screen
{
    this->info = { 0 };
    box(win.get(), 0, 0);
    refresh();
}

void Window::draw()
{
}
void Window::refresh()
{
    draw();
    wrefresh(win.get());
}
Window::Window(WindowInfo info)
    : win(std::shared_ptr<WINDOW>(newwin(info.lines, info.columns,
                    info.x, info.y)))
{
    this->info = info;

}

Window::~Window()
{
    delwin(win.get());
}

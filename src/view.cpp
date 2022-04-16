#include "view.h"
#include <iostream>

View::View()
{
    // add a full-screen window
    std::shared_ptr<Window> w(new Window);
    this->windows.push_back(w);
    this->active_window = w;

}

void View::update()
{
    for (auto &w : windows)
    {
        w->refresh();
    }
}

View::~View()
{

}

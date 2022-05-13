#include "window.h"

Window::Window() 
    : _views()
{
    auto view = std::make_shared<View>();
    _current_view = view;
    _views.push_back(view);
}

void Window::update()
{
    for (auto &e : _views) {
        e->update();
    }
}

Window::~Window()
{

}
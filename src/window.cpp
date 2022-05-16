#include "window.h"
#include "editor.h"
#include <cassert>

Window::Window() 
    : _views()
{
}

void Window::add_view(std::shared_ptr<View> view, bool active)
{
    _views.push_back(view);
    if (active)
    {
        _current_view = view;
        view->set_active(true);
    }
}

void Window::handle(wint_t key)
{
    switch (key)
    {
    case KEY_F(1):
        _status = WindowStatus::QUIT;
        break;
    default:
        _current_view->key_input_event(key);
    }
    if (_current_view->status() == ViewStatus::EXIT)
    {
        if (_views.size() == 1)
            _status = WindowStatus::QUIT;
    }
}

void Window::update_all()
{
    //update all
    for (auto &e : _views) {
        e->update();
    }

}

void Window::update()
{
    //just update current view
    _current_view->update();
}

Window::~Window()
{
}
#include "window.h"
#include "editor.h"
#include "utils.h"
#include <cassert>
Window::Window() 
    : _views()
{
    init_ncurses();
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

void Window::handle(int key)
{
    switch (key)
    {
    case ctrl('q'):        //ESC or ALT
        _status = WindowStatus::QUIT;
        break;
    default:
        _current_view->key_input_event(key);
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
    endwin();
}
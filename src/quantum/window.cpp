#include "window.h"
#include "editor.h"
#include "components/status_line.h"
#include <cassert>

Window::Window(std::shared_ptr<StatusLine> status_line)
    : _views(), _changed(true), _status_line(status_line)
{
}

void Window::add_view(std::shared_ptr<View> view, bool active)
{
    _views.push_back(view);
    if (active)
    {
        _current_view = _views.end();
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
        (*_current_view)->key_input_event(key);
        _changed = true;
    }

    if ((*_current_view)->status() == ViewStatus::EXIT)
    {
        if (_views.size() == 1)
            _status = WindowStatus::QUIT;
    }
}

void Window::update_all()
{
    // update all
    for (auto &e : _views)
    {
        e->update();
    }
}

void Window::update()
{
    if (_changed)
    {
        update_all();
        if (_status_line)
            _status_line->update();
        doupdate();
        _changed = false;
    }
}

Window::~Window()
{
}
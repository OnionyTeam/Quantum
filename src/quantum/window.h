#ifndef _QUANTUM_WINDOW_H__
#define _QUANTUM_WINDOW_H__

#include "view.h"
#include <list>

enum class WindowStatus
{
    NORMAL,
    QUIT
};

class Window
{
    using view_type = std::shared_ptr<View>;
    using view_iterator = std::list<view_type>::iterator;

    // typedef std::shared_ptr<View> view_type;
    // typedef std::list<view_type>::iterator view_iterator;
private:
    std::list<view_type> _views;
    view_iterator _current_view;
    std::shared_ptr<StatusLine> _status_line;
    WindowStatus _status;
    bool _changed;

public:
    Window(std::shared_ptr<StatusLine> status_line = nullptr);
    void add_view(view_type view, bool active = false);
    void set_status_line(std::shared_ptr<StatusLine> status_line) { _status_line = status_line; }
    void next_window()
    {
        if (_current_view != _views.end())
            _current_view++;
    }
    void previous_window()
    {
        if (_current_view != _views.begin())
            _current_view--;
    }
    void set_active(view_iterator &view)
    {
        _current_view = view;
        (*view)->set_active(true);
    }
    const view_type get_current_view() const { return *_current_view; }
    view_type get_current_view() { return *_current_view; }
    const WindowStatus status() const { return _status; }
    void refrush() { _changed = true; }
    void handle(wint_t key);
    void update();
    void update_all();
    std::shared_ptr<StatusLine> get_status_line() { return _status_line; }
    ~Window();
};

#endif //_QUANTUM_WINDOW_H__

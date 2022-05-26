#ifndef _QUANTUM_VIEW_H__
#define _QUANTUM_VIEW_H__

#include <vector>
#include <memory>
#include <ncursesw/ncurses.h>
#include "editor_config.h"
#include "buffer.h"

enum class ViewStatus
{
    NORMAL,
    EXIT
};

class StatusLine;

class View
{
    friend StatusLine;
protected:
    std::vector<std::shared_ptr<Buffer>> _buffers;
    std::shared_ptr<Buffer> _current_buffer;
    WindowInfo _window_info;
    std::shared_ptr<WINDOW> _window;
    CursorInfo _cursor_info;    // abstract position
    bool _read_only;
    bool _active;
    unsigned int _scroll_x;
    unsigned int _scroll_y;
    unsigned int _last_cursor_x;
    ViewStatus _status;
public:
    View(const WindowInfo &info = {0});
    virtual void update() {};
    virtual void key_input_event(wint_t key) {};
    void set_active(bool k) { _active = k; }
    bool active() const { return _active; }
    ViewStatus status() { return _status; }

    //Using this method is safe
    virtual void move_up();
    virtual void move_down();
    virtual void move_left();
    virtual void move_right();

    virtual void scroll_up();
    virtual void scroll_down();
    ~View();
};

#endif //_QUANTUM_VIEW_H__

#ifndef _QUANTUM_VIEW_H__
#define _QUANTUM_VIEW_H__

#include <vector>
#include <memory>
#include <ncurses.h>
#include "editor_config.h"
#include "buffer.h"

class View 
{
protected:
    std::vector<std::shared_ptr<Buffer>> _buffers;
    std::shared_ptr<Buffer> _current_buffer;
    std::shared_ptr<WINDOW> _window;
    CursorInfo _cursor_info;
    unsigned int _last_cursor_x;
    bool _read_only;
    bool _active;
    WindowInfo _window_info;
public:
    View(const WindowInfo &info = {0});
    virtual void update() {};
    virtual void key_input_event(int key) {};
    void set_active(bool k) { _active = k; }
    bool active() const { return _active; }

    //Using this method is safe
    virtual void move_up();
    virtual void move_down();
    virtual void move_left();
    virtual void move_right();
    ~View();
};

#endif //_QUANTUM_VIEW_H__

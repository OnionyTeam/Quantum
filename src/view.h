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
    WindowInfo _window_info;
public:
    View(const WindowInfo &info = {0});
    void update();
    ~View();
};

#endif //_QUANTUM_VIEW_H__

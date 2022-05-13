#ifndef _QUANTUM_VIEW_H__
#define _QUANTUM_VIEW_H__

#include <vector>
#include <memory>
#include "editor_config.h"
#include <ncurses.h>
#include "buffer.h"

class View 
{
public:
    View();
    void update();
    ~View();
private:
    std::vector<std::shared_ptr<Buffer>> _buffers;
    std::shared_ptr<Buffer> _current_buffer;
    std::shared_ptr<WINDOW> _window;
    EditorConfig _config;
};

#endif //_QUANTUM_VIEW_H__

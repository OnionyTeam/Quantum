#ifndef _QUANTUM_WINDOW_H__
#define _QUANTUM_WINDOW_H__

#include "view.h"

class Window 
{
public:
    Window();
    void update();
    ~Window();
private:
    std::vector<std::shared_ptr<View>> _views;
    std::shared_ptr<View> _current_view;
};

#endif //_QUANTUM_WINDOW_H__
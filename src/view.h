#ifndef _QUANTUM_VIEW_H__
#define _QUANTUM_VIEW_H__

#include <vector>
#include <ncurses.h>
#include <memory>
#include "window.h"

// View is used to render the screen
class View
{

public:
    View();
    void update();
    ~View();

private:
    std::vector<std::shared_ptr<Window>> windows;    // child windows
    std::shared_ptr<Window> active_window;

};

#endif //_QUANTUM_VIEW_H__

#ifndef _QUANTUM_VIEW_H__
#define _QUANTUM_VIEW_H__

#include <vector>
#include "window.h"

// View is used to render the screen
class View
{

public:
    View();
    ~View();

private:
    std::vector<Window> windows;    // child windows

};

#endif //_QUANTUM_VIEW_H__

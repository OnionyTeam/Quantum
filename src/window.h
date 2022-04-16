#ifndef _QUANTUM_WINDOW_H__
#define _QUANTUM_WINDOW_H__

#include <memory>
#include "editor.h"

// description a window
struct WindowInfo
{
    int lines;
    int columns;
    int x;
    int y;
};

class Window
{
public:
    Window(WindowInfo info);
    ~Window();

private:
    Editor editor;      // child component
    WindowInfo info;

};
#endif //_QUANTUM_WINDOW_H__

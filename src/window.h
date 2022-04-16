#ifndef _QUANTUM_WINDOW_H__
#define _QUANTUM_WINDOW_H__

#include <memory>
#include <ncurses.h>
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
    Window();
    Window(WindowInfo info);
    void draw();
    void refresh();
    ~Window();

private:
    std::shared_ptr<Editor> editor;      // child component
    std::shared_ptr<WINDOW> win;
    WindowInfo info;

};
#endif //_QUANTUM_WINDOW_H__

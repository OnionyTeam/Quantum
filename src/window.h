#ifndef _QUANTUM_WINDOW_H__
#define _QUANTUM_WINDOW_H__

#include "editor.h"

class Window 
{
public:
    Window(const std::string &filename);
    void update();
    void open_file(const std::string &filename);
    ~Window();
private:
    std::vector<std::shared_ptr<Editor>> _editors;
    std::shared_ptr<Editor> _current_editor;
};

#endif //_QUANTUM_WINDOW_H__
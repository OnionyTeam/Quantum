#include "window.h"
#include "editor.h"
#include "utils.h"
#include <cassert>
Window::Window(const std::string &filename) 
    : _editors()
{
    init_ncurses();
    auto editor = std::make_shared<Editor>(filename, true);
    _current_editor = editor;
    _editors.push_back(editor);
    
    update_all();
}

void Window::update_all()
{
    //update all
    for (auto &e : _editors) {
        e->update();
    }

}

int Window::loop()
{
    while (true)
    {
        int input = getch();
        _current_editor->key_input_event(input);
        update();
    }
    return 0;
}

void Window::open_file(const std::string &filename)
{
    if (!_editors.empty()) {
        _current_editor->open_file(filename);
    } else {
        auto editor = std::make_shared<Editor>(filename);
        _current_editor = editor;
        _editors.push_back(editor);
    }
}
void Window::update()
{
    //just update current editor
    _current_editor->update();
}

Window::~Window()
{
    endwin();
}
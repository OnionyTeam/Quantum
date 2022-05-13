#include "window.h"
#include "editor.h"
Window::Window(const std::string &filename) 
    : _editors()
{
    auto editor = std::make_shared<Editor>(filename);
    _current_editor = editor;
    _editors.push_back(editor);
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
    for (auto &e : _editors) {
        e->update();
    }
    refresh();
}

Window::~Window()
{

}
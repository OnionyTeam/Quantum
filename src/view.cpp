#include "view.h"

View::View() 
    : _buffers(), _config()
{
    _config.filename = "untitled";
    _buffers.push_back(std::make_shared<Buffer>());
    _current_buffer = _buffers.back();
    _window = std::shared_ptr<WINDOW>(newwin(0, 0, 0, 0),
    [](WINDOW* w){
        delwin(w);
    });
    redrawwin(_window.get());
}

void View::update()
{
    mvwprintw(_window.get(), 5, 5, "HELLO, WORLD!");
    wrefresh(_window.get());
}

View::~View()
{
}
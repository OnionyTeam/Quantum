#include "view.h"

View::View(const WindowInfo &info) 
    : _buffers(), _window_info(info)
{
    _buffers.push_back(std::make_shared<Buffer>());
    _current_buffer = _buffers.back();
    _window = std::shared_ptr<WINDOW>(newwin(_window_info.rows, 
    _window_info.cols, _window_info.x, _window_info.y),
    [](WINDOW* w){
        delwin(w);
    });
    redrawwin(_window.get());
}

View::~View()
{
}
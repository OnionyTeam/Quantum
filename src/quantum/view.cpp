#include "view.h"

View::View(const WindowInfo &info)
    : _buffers(), _window_info(info),
      _cursor_info{0},
      _read_only(false),
      _scroll_x(0), _scroll_y(0), _last_cursor_x(0), _status(ViewStatus::NORMAL)
{
    _buffers.push_back(std::make_shared<Buffer>());
    _current_buffer = _buffers.back();
    _window = std::shared_ptr<WINDOW>(newwin(_window_info.lines,
                                             _window_info.cols, _window_info.y, _window_info.x),
                                      [](WINDOW *w)
                                      {
                                          delwin(w);
                                      });
    // leaveok(_window.get(), true);
    // redrawwin(_window.get());
}

void View::move_down()
{
    if (_current_buffer->lines.size() > _cursor_info.y + 1)
    {
        if (_cursor_info.y >= _window_info.lines) // out of showing range
        {
            scroll_down();
        }
        _last_cursor_x = _cursor_info.x;
        _cursor_info.y++;
        auto size = _current_buffer->lines[_cursor_info.y].size();
        if (_last_cursor_x < size)
        {
            _cursor_info.x = _last_cursor_x;
        }
        else
        {
            _cursor_info.x = size;
            _last_cursor_x = _cursor_info.x;
        }
    }
}

void View::move_up()
{
    if (_cursor_info.y > 0)
    {
        if (_cursor_info.y - _scroll_y > 0)
        {
            scroll_up();
        }
        _last_cursor_x = _cursor_info.x;
        _cursor_info.y--;
        auto size = _current_buffer->lines[_cursor_info.y].size();
        if (_last_cursor_x < size)
        {
            _cursor_info.x = _last_cursor_x;
        }
        else
        {
            _cursor_info.x = size;
            _last_cursor_x = _cursor_info.x;
        }
    }
}

void View::move_left()
{
    if (_cursor_info.x > 0)
        _cursor_info.x--;
}

void View::move_right()
{
    if (_current_buffer->lines[_cursor_info.y].size() > _cursor_info.x)
        _cursor_info.x++;
}

void View::scroll_down()
{
    if (_scroll_y < _current_buffer->lines.size() - 1)
    {
        _scroll_y++;
    }
}

void View::scroll_up()
{
    if (_scroll_y > 0)
    {
        _scroll_y--;
    }
}

View::~View()
{
}

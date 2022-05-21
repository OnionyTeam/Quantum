#include "status_line.h"
#include <cstdlib>
#include <sstream>

StatusLine::StatusLine(const std::shared_ptr<View> &view, const WindowInfo &info)
    : View(info), _target(view)
{
    _read_only = true;
}

void StatusLine::update()
{
    wchar_t wstr[100];
    swprintf(wstr, 100, L"CURSOR POS: (X:%d Y:%d)", _target->_cursor_info.x, _target->_cursor_info.y);
    mvwaddwstr(_window.get(), 0, 0, wstr);
    wrefresh(_window.get());
}
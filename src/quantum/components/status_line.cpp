#include "status_line.h"
#include <fmt/format.h>
#include <fmt/xchar.h>

StatusLine::StatusLine(const std::shared_ptr<View> &view, const WindowInfo &info)
    : View(info), _target(view), _info_part(L"", Align::RightAligh), _message_part(L"", Align::LeftAlign)
{
    _read_only = true;
    init_pair(1,COLOR_BLACK, COLOR_WHITE);
    wbkgd(_window.get(), COLOR_PAIR(1));
    leaveok(_window.get(), true);
}

void StatusLine::show_message(const std::wstring &str, size_t timeout)
{
    _message_part.first = std::wstring(L"Message: ") + str;
}


void StatusLine::update()
{
    WINDOW *w = _window.get();
    werase(w);
    _info_part.first = fmt::format(L"POS: (X:{}, Y{})", _target->_cursor_info.x, _target->_cursor_info.y);
    draw::draw_text_with_align(w, _info_part.first.c_str(), 0, Align::RightAligh);
    draw::draw_text_with_align(w, _message_part.first.c_str(), 0, Align::LeftAlign);
    wrefresh(w);
}
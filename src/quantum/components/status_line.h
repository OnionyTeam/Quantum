#ifndef _QUANTUM_STATUS_LINE_H__
#define _QUANTUM_STATUS_LINE_H__

#include "../view.h"
#include "../draw/draw_helper.h"
#include <string>

class Window;
class StatusLine : public View
{
private:
    std::pair<std::wstring, Align> _info_part;
    std::pair<std::wstring, Align> _message_part;

public:
    StatusLine(std::shared_ptr<Window> parent, const WindowInfo &info = {0});
    void show_message(const std::wstring &str, size_t timeout = 2000);
    void update() override;
};

#endif //_QUANTUM_STATUS_LINE_H__

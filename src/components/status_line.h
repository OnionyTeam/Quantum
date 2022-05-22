#ifndef _QUANTUM_STATUS_LINE_H__
#define _QUANTUM_STATUS_LINE_H__

#include "../view.h"
#include "../editor.h"
#include "../draw/draw_helper.h"
#include <timer/timer.h>
#include <array>


class StatusLine : public View
{
private:
    std::shared_ptr<View> _target; // look for
    std::pair<std::wstring, Align> _info_part;
    std::pair<std::wstring, Align> _message_part;
    std::unique_ptr<Timer> _timer;

public:
    StatusLine(const std::shared_ptr<View> &view, const WindowInfo &info = {0});
    void show_message(const std::wstring_view str);
    void update() override;
};

#endif //_QUANTUM_STATUS_LINE_H__
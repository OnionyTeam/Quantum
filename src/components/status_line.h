#ifndef _QUANTUM_STATUS_LINE_H__
#define _QUANTUM_STATUS_LINE_H__

#include "../view.h"
#include "../editor.h"

class StatusLine : public View
{
private:
    std::shared_ptr<View> _target; // look for
public:
    StatusLine(const std::shared_ptr<View> &view, const WindowInfo &info = {0});
    void update() override;
};



#endif //_QUANTUM_STATUS_LINE_H__
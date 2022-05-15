#ifndef _QUANTUM_WINDOW_H__
#define _QUANTUM_WINDOW_H__

#include "editor.h"
#include "keymap/keymap.h"

enum class WindowStatus
{
    NORMAL,
    QUIT
};

class Window 
{
private:
    std::vector<std::shared_ptr<View>> _views;
    std::shared_ptr<View> _current_view;
    WindowStatus _status;
public:
    Window();
    void add_view(std::shared_ptr<View> view, bool active = false);
    void set_active(std::shared_ptr<View>& view) { _current_view = view; view->set_active(true); };
    const std::shared_ptr<View> get_current_view() const { return _current_view; };
    std::shared_ptr<View> get_current_view() { return _current_view; };
    const WindowStatus status() const { return _status; };
    void handle(int key);
    void update();
    void update_all();
    ~Window();
};

#endif //_QUANTUM_WINDOW_H__
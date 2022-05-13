#ifndef _QUANTUM_EDITOR_H__
#define _QUANTUM_EDITOR_H__

#include "view.h"
#include <stack>
class Editor : public View
{
private:
    EditorInfo _editor_info;
    std::vector<int> _changed_lines;         //it will record which rows have been modified
    bool _active;
public:
    Editor(const std::string &filename = "", bool active = false, const WindowInfo &info = {0});
    Editor(const EditorInfo &editor_info, const WindowInfo &window_info = {0});
    void open_file(const std::string &filename);
    void update();
    void set_active(bool k) { _active = k; };
    bool active() { return _active; }
    ~Editor() {}
private:
    void load_file();
    void init();
    void update_buffer();
};

#endif //_QUANTUM_EDITOR_H__
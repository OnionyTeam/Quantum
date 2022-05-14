#ifndef _QUANTUM_EDITOR_H__
#define _QUANTUM_EDITOR_H__

#include "view.h"

class Command;
class Editor : public View
{
    friend Command;
private:
    EditorInfo _editor_info;
    std::vector<int> _changed_lines;         //it will record which rows have been modified
    unsigned int _last_cursor_x;
    bool _active;
public:
    Editor(const std::string &filename = "", bool active = false, const WindowInfo &info = {0});
    Editor(const EditorInfo &editor_info, const WindowInfo &window_info = {0});
    void key_input_event(int key);
    void open_file(const std::string &filename);
    void update();
    void set_active(bool k) { _active = k; };
    bool active() { return _active; }
    void type_char(char c);       //type from the current cursor position
    const EditorInfo& get_editor_info() const { return _editor_info; }

    //Using this method is safe
    void move_up();
    void move_down();
    void move_left();
    void move_right();

    ~Editor() {}
private:
    void load_file();
    void init();
    void update_buffer();
};

#endif //_QUANTUM_EDITOR_H__
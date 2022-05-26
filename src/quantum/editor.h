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
public:
    Editor(const std::string &filename = "", const WindowInfo &info = {0}, bool active = false);
    Editor(const EditorInfo &editor_info, const WindowInfo &window_info = {0});

    void open_file(const std::wstring &filename);
    void save_file();

    void key_input_event(wint_t key) override;
    void update() override;
    void update_cursor();
    void update_buffer();
    void type_char(wchar_t c);       //type from the current cursor position
    const EditorInfo& get_editor_info() const { return _editor_info; }

    ~Editor() {}
private:
    void load_file();
    void init();
};

#endif //_QUANTUM_EDITOR_H__
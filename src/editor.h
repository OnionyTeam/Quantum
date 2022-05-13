#ifndef _QUANTUM_EDITOR_H__
#define _QUANTUM_EDITOR_H__

#include "view.h"

class Editor : public View
{
private:
    EditorInfo _editor_info;
    std::vector<int> _changed_lines;         //it will record which rows have been modified
public:
    Editor(const std::string &filename = "", const WindowInfo &info = {0});
    Editor(const EditorInfo &editor_info, const WindowInfo &window_info = {0});
    void open_file(const std::string &filename);
    void update();
    ~Editor() {}
private:
    void load_file();
    void init();
    void update_buffer();
};

#endif //_QUANTUM_EDITOR_H__
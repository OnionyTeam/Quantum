/**
 *  Description:
 *      Editor is a component
 *  Author: flingpig233-cpu
 */

#ifndef _QUANTUM_EDITOR_H__
#define _QUANTUM_EDITOR_H__

#include <memory>
#include "buffer.h"
#include "editor_config.h"
#include "window.h"

class Editor
{
    friend Window;
public:
    Editor(std::string filename = "");
    void open_file(std::string filename = "");
    void load_file();      // load file to buf
    void update_view();

private:
    std::unique_ptr<Buffer> buf;
    EditorConfig config;
};


#endif // _QUANTUM_EDITOR_H__

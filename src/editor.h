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

class Editor
{
public:
    Editor(std::string filename = "");
    void open_file();
    void load_file(std::string filename = "");      // load file to buf
    void update_view();

private:
    std::unique_ptr<Buffer> buf;
    EditorConfig config;
};


#endif // _QUANTUM_EDITOR_H__

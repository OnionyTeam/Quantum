#ifndef _QUANTUM_EDITOR_CONFIG_H__
#define _QUANTUM_EDITOR_CONFIG_H__

#include <string>

struct CursorInfo
{
    int x;
    int y;
};

// this struct saved editor's config
struct EditorInfo
{
    std::string filename;
    CursorInfo cursor_info;
    bool refresh_all;
    bool new_file;
};

struct WindowInfo 
{
    int cols;
    int rows;
    int x;
    int y;
};

#endif //_QUANTUM_EDITOR_CONFIG_H__

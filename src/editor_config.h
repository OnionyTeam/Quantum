#ifndef _QUANTUM_EDITOR_CONFIG_H__
#define _QUANTUM_EDITOR_CONFIG_H__

#include <string>

struct CursorInfo
{
    unsigned int x;
    unsigned int y;
};

// this struct saved editor's config
struct EditorInfo
{
    std::string filename;
    bool refresh_all;
    bool new_file;
    bool modified;
    bool read_only;
};

struct WindowInfo 
{
    unsigned int cols;
    unsigned int lines;
    unsigned int x;
    unsigned int y;
};

#endif //_QUANTUM_EDITOR_CONFIG_H__

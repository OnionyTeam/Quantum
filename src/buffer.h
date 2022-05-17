/**
 *  Description:
 *      Buffer saves the content of the file
 */


#ifndef _QUANTUM_BUFFER_H__
#define _QUANTUM_BUFFER_H__

#include <string>
#include <vector>
#include "global_config.h"


struct Buffer
{
    std::vector<std::wstring> lines;

    Buffer();
    void insert_line(const std::wstring& line, config::position_type pos);
    void append_line(const std::wstring& line);
    void delete_line(config::position_type pos);
    void remove_line(config::position_type pos);
    int get_real_size(config::position_type y);


};

#endif //_QUANTUM_BUFFER_H__

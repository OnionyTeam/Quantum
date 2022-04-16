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
public:
    std::vector<std::string> lines;

    Buffer();
    void insert_line(std::string& line, config::position_type pos);
    void append_line(std::string& line);
    void remove_line(config::position_type pos);


};

#endif //_QUANTUM_BUFFER_H__

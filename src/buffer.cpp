#include "buffer.h"


Buffer::Buffer()
{
    
}

void Buffer::insert_line(std::string line, config::position_type pos)
{
    this->lines.insert(lines.begin() + pos, line);
}
void Buffer::append_line(std::string line)
{
    this->lines.push_back(line);
}

void Buffer::remove_line(config::position_type pos)
{
    this->lines.erase(lines.begin() + pos);
}


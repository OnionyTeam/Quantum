#include "buffer.h"


Buffer::Buffer()
{
    
}

void Buffer::insert_line(std::string& line, config::position_type pos)
{
    this->lines.insert(lines.begin() + pos, std::move(line));
}
void Buffer::append_line(std::string& line)
{
    this->lines.push_back(std::move(line));
}

void Buffer::remove_line(config::position_type pos)
{
    this->lines.erase(lines.begin() + pos);
}


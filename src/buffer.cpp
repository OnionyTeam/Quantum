#include "buffer.h"


Buffer::Buffer()
    : lines()
{
}


void Buffer::insert_line(const std::wstring& line, config::position_type pos)
{
    this->lines.insert(lines.begin() + pos, line);
}
void Buffer::append_line(const std::wstring& line)
{
    this->lines.push_back(line);
}

void Buffer::remove_line(config::position_type pos)
{
    this->lines.erase(lines.begin() + pos);
}
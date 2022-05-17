#include "buffer.h"
#include <ctype.h>

Buffer::Buffer()
    : lines()
{
}


int Buffer::get_real_size(config::position_type y)
{
    return wcswidth(lines[y].c_str(), lines[y].size());
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
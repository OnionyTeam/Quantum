#include "editor.h"
#include <fstream>
#include <iostream>

Editor::Editor(std::string filename)
    : buf(new Buffer())
{
    config.filename = filename;
}

void Editor::open_file(std::string filename)
{
    config.filename = filename;
    load_file();
}

void Editor::load_file()
{
    std::ifstream infile(this->config.filename.c_str());
    if(infile.is_open())
    {
        while(!infile.eof())
        {
            std::string temp;
            std::getline(infile, temp);
            buf->append_line(temp);
        }
    }
    else
    {
        std::cerr << "Cannot open file: '" << config.filename << std::endl;
        buf->append_line("");
    }
    update_view();
}

void Editor::update_view()
{
    for (size_t i = 0; i < buf->lines.size(); ++i)
    {
        std::cout << buf->lines.at(i) << std::endl;
    }
}

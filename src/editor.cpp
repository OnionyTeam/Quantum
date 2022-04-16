#include "editor.h"

Editor::Editor(std::string filename)
    this->config {}
{
    config.filename = filename;
}

void Editor::open_file(std::string filename)
{
    config.filename = filename;
}

void Editor::load_file()
{
    ifstream infile(config.filename.c_str());
    if(infile.is_open())
    {
        while(!infile.eof())
        {
            string temp;
            getline(infile, temp);
            buf->appendLine(temp);
        }
    }
    else
    {
        cerr << "Cannot open file: '" << fn << endl;
        buff->appendLine("");
    }
}

#include "quantum.h"
#include <iostream>
#include <ncurses.h>
#include "editor.h"
#include "global_config.h"

Quantum::Quantum(int argc, char* argv[])
    : parser(argc, argv, config::program_description)
{
    parser_init();
    parser.run_and_exit_if_error();
}

int Quantum::run()
{
    // Parse the args
    std::string filename = parser.get<std::string>("f");

    if ("" == filename)     // if did not select a filename to open
    {
        
    }
    std::cout << filename << std::endl;
    Editor e(filename);
    e.load_file();


    return 0;
}

void Quantum::ncurses_init()
{
    initscr();
    noecho();
    cbreak();               // Disable line buffering
    keypad(stdscr, true);
}

void Quantum::parser_init()
{
    parser.set_optional<std::string>("f", "file", "", "Open a file");
}
Quantum::~Quantum()
{

}

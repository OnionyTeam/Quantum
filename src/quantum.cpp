#include "quantum.h"
#include <iostream>
#include <ncurses.h>
#include "window.h"
#include "global_config.h"

Quantum::Quantum(int argc, char* argv[])
    : parser(argc, argv, config::program_description)
{
    parser_init();
    ncurses_init();
    parser.run();
}

int Quantum::run()
{
    // Parse the args
    std::string filename = parser.get<std::string>("f");

    // init ncurses screen, making main window too
    initscr();
    // change how terminal input works
    // initialise colours
    start_color();
    // don't echo typed characters back
    noecho();
    // characters read 1 by 1
    cbreak();
    // get all keys
    keypad(stdscr, true);

    Window w;
    while (true) {
        w.update();
    }
    refresh();
    endwin();

    return 0;
}

void Quantum::ncurses_init()
{
    initscr();
    clear();
    /* noecho(); */
    /* cbreak();               // Disable line buffering */
    /* keypad(stdscr, true); */
}

void Quantum::parser_init()
{
    parser.set_optional<std::string>("f", "file", "", "Open a file");
}

Quantum::~Quantum()
{

}

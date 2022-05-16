/**
 *  Descirption:
 *      This header file contains some global configuration.
 */


#ifndef _QUANTUM_GLOBAL_CONFIG_H__
#define _QUANTUM_GLOBAL_CONFIG_H__

#include <string>
#include <assert.h>
#include <ncursesw/ncurses.h>
#include "utils.h"

// program description
namespace config {

    using position_type = size_t;

    const static std::string program_description = "Quantum is a console-run editor and it has special shortcuts to help "
        "people code quickly. But it's still in the preparatory stage";

    struct NcursesInfo
    {
        int cols;
        int lines;

        NcursesInfo() {
            setlocale(LC_ALL, "");
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
            cols = COLS;
            lines = LINES;
        }
        ~NcursesInfo() { endwin(); }
    };
    static NcursesInfo ncurses_info;
} // namespace config



#endif //_QUANTUM_GLOBAL_CONFIG_H__

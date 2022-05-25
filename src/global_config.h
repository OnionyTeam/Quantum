/**
 *  Descirption:
 *      This header file contains some global configuration.
 */

#ifndef _QUANTUM_GLOBAL_CONFIG_H__
#define _QUANTUM_GLOBAL_CONFIG_H__

#include <fstream>
#include <string>
#include <fmt/os.h>
#include <assert.h>
#include <ncursesw/ncurses.h>
#include "utils.h"

// program description
namespace config
{
    using position_type = size_t;
    typedef wchar_t char_type;
    const static char endl = '\n';
    const static std::string program_description = "Quantum is a console-run editor and it has special shortcuts to help "
                                                   "people code quickly. But it's still in the preparatory stage";


    struct NcursesInfo
    {
        unsigned int cols;
        unsigned int lines;
        NcursesInfo()
        {
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
            cols = static_cast<unsigned int>(COLS);
            lines = static_cast<unsigned int>(LINES);
        }

        ~NcursesInfo() { endwin(); }
    };
    static NcursesInfo ncurses_info;

    static fmt::v8::ostream logger = fmt::output_file("out.txt");
} // namespace config

#endif //_QUANTUM_GLOBAL_CONFIG_H__

/**
 *  Descirption:
 *      This header file contains some global configuration.
 */

#ifndef _QUANTUM_GLOBAL_CONFIG_H__
#define _QUANTUM_GLOBAL_CONFIG_H__

#include <fstream>
#include <string>
#include <assert.h>
#include <ncursesw/ncurses.h>
#include "utils.h"

// program description
namespace config
{
    const static char endl = '\n';
    using position_type = size_t;

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

    class Logger
    {
    private:
        ::std::wfstream stream;

    public:
        Logger() : stream("out.txt", std::ios_base::out){};


        template <typename T>
        Logger& operator<<(T element) 
        {
            stream << element << std::flush;
            return *this;
        }

        ~Logger() { stream << std::flush; stream.close(); }
    };
    static Logger logger;
} // namespace config

#endif //_QUANTUM_GLOBAL_CONFIG_H__

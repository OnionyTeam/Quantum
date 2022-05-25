#include "quantum.h"
#include <iostream>
#include <ncursesw/ncurses.h>
#include <thread>
#include "window.h"
#include "components/status_line.h"
#include "global_config.h"

Quantum::Quantum(int argc, char* argv[])
    : parser(argc, argv, config::program_description)
{
    parser_init();
    parser.run();
}

int Quantum::run()
{
    // Parse the args
    std::string filename = parser.get<std::string>("f");

    Window w;
    auto editor = std::make_shared<Editor>(filename, WindowInfo {config::ncurses_info.cols, config::ncurses_info.lines - 1, 0, 0});
    // auto editor2 = std::make_shared<Editor>(filename, WindowInfo {10, 10, 5, 5});
    auto status_line = std::make_shared<StatusLine>(editor, WindowInfo {config::ncurses_info.cols, 1, 0, config::ncurses_info.lines - 1});
    w.add_view(status_line, false);
    w.add_view(editor, true);
    w.update_all();
    timeout(0);
    while (w.status() != WindowStatus::QUIT)
    {
        wint_t ch;
        get_wch(&ch);
        status_line->show_message(std::to_wstring(ch), 1000);
        if (ch)
            w.handle(ch);
        w.update();
    }
    return 0;

}

void Quantum::parser_init()
{
    parser.set_optional<std::string>("f", "file", "", "Open a file");
}

Quantum::~Quantum()
{

}

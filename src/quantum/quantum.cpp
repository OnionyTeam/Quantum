#include "quantum.h"
#include <iostream>
#include <ncursesw/ncurses.h>
#include <thread>
#include "window.h"
#include "components/status_line.h"
#include "editor.h"
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

    auto w = std::make_shared<Window>();
    auto status_line = std::make_shared<StatusLine>(w, WindowInfo {config::ncurses_info.cols, 1, 0, config::ncurses_info.lines - 1});
    w->set_status_line(status_line);
    // auto editor2 = std::make_shared<Editor>(filename, WindowInfo {10, 10, 5, 5});
    auto editor = std::make_shared<Editor>(filename, WindowInfo {config::ncurses_info.cols, (config::ncurses_info.lines - 1) / 2, 0, 0}, w);
    // auto editor2 = std::make_shared<Editor>(filename,
    //  WindowInfo {config::ncurses_info.cols, (config::ncurses_info.lines - 1) / 2, 0, (config::ncurses_info.lines - 1)}, w);
    // w->add_view(editor2, true);
    w->add_view(editor, true);
    w->update_all();
    // timeout(0);
    while (w->status() != WindowStatus::QUIT)
    {
        wint_t ch;
        get_wch(&ch);
        if (ch)
            w->handle(ch);
        config::logger << L"OK" << config::endl;
        w->update();
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

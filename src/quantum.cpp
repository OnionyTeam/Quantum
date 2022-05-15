#include "quantum.h"
#include <iostream>
#include <ncurses.h>
#include "window.h"
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
    auto editor = std::make_shared<Editor>(filename);
    w.add_view(editor, true);
    while (w.status() != WindowStatus::QUIT)
    {
        int ch = getch();
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

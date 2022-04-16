#include "quantum.h"
#include <iostream>
#include "global_config.h"

Quantum::Quantum(int argc, char* argv[])
    : parser(argc, argv, config::program_description)
{
    configure_parser();
    parser.run_and_exit_if_error();
}

int Quantum::run()
{
    // Parse the args
    std::string filename = parser.get<std::string>("f");
    if ("" == filename)
        std::cout << "SHIT!" << std::endl;

    std::cout << filename << std::endl;
    


    return 0;
}

void Quantum::configure_parser()
{
    parser.set_optional<std::string>("f", "file", "", "Open a file");
}
Quantum::~Quantum()
{

}
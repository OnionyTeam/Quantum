#include "ProgramEntry.hpp"

QuantomProgram::QuantomProgram(int argc, char** argv) : args(std::vector<std::string>()) {
    for (int i = 0; i < argc; i++) {
        args.push_back(argv[i]);
    }
}

void QuantomProgram::runProgram() {
    // Write your code here
}

QuantomProgram::~QuantomProgram() {
    if (QuantomProgram::debug) {
        std::cout << "App exited normally." << std::endl;
    }
    // Write your code here when the app exits
}

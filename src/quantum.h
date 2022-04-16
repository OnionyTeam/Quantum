
#ifndef _QUANTUM_QUANTUM_H__
#define _QUANTUM_QUANTUM_H__

#include <string>
#include "libs/cmd_parser/cmdparser.h"

class Quantum
{

public:

    static std::string program_description;
public:
    Quantum(int argc, char* argv[]);

    int run();

    ~Quantum();

private:
    cli::Parser parser;

private:
    void configure_parser();
};

#endif //__QUANTUM_QUANTUM_H_

#ifndef _QUANTUM_QUANTUM_H__
#define _QUANTUM_QUANTUM_H__

#include <string>
#include "cmd_parser/cmdparser.h"

class Quantum
{

public:
    Quantum(int argc, char* argv[]);

    int run();
    ~Quantum();

private:
    cli::Parser parser;

private:
    void parser_init();
};

#endif //__QUANTUM_QUANTUM_H_

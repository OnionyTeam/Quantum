
#ifndef __QUANTUM_QUANTUM_H_
#define __QUANTUM_QUANTUM_H_

#include <iostream>
#include <string>
#include <vector>

class Quantum
{
public:
    Quantum(int argc, char* argv[]);

private:
    std::vector<std::string> args;
};

#endif //__QUANTUM_QUANTUM_H_

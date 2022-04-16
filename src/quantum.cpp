#include "quantum.h"
#include <iostream>

Quantum::Quantum(int argc, char* argv[])
{
    for (int i = 0; i < argc; ++i)
    {
        this->args.push_back(std::string(argv[i]));
    }
    for (auto &a : this->args)
    {
        std::cout << a << std::endl;
    }
}

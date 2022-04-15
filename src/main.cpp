#include "ProgramEntry.hpp"
using namespace std;

int main(int argc, char **argv) {
    QuantomProgram prog(argc, argv);
    prog.runProgram();
    return 0;
}

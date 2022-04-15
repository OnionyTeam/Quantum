#ifndef A4CF1EA3_1DB2_4F6E_8256_B0738F9E0E67
#define A4CF1EA3_1DB2_4F6E_8256_B0738F9E0E67

#include <vector>
#include <string>
#include <iostream>

class QuantomProgram {
    private:
    std::vector<std::string> args;
    public:

    // Constants
    static const bool debug = true;

    // Methods
    QuantomProgram(int argc, char ** argv);
    void runProgram();
    ~QuantomProgram();
};

#endif /* A4CF1EA3_1DB2_4F6E_8256_B0738F9E0E67 */

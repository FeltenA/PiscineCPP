#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Incorrect number of arguments" << std::endl;
        return (0);
    }
    try {
        RPN rpn;
        int result = rpn.evaluateString(argv[1]);
        std::cout << result << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error" << std::endl;
    }
    return (0);
}
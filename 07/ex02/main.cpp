#include "Array.hpp"
#include <string>

int main(void) {
    Array<int> test(10);
    Array<std::string> test2(10);

    test[5] = 3;
    test2[7] = "test";
    std::cout << test[5] << std::endl;
    std::cout << test2[7] << std::endl;
    try {
        std::cout << test[10] << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "not in range" << std::endl;
    }
    
    test[5] = 12;
    Array<int> test3(test);
    Array<int> test4;

    test4 = test;
    std::cout << test[5] << std::endl;
    std::cout << test3[5] << std::endl;
    std::cout << test4[5] << std::endl;

    Array<std::string> test5;

    return 0;
}
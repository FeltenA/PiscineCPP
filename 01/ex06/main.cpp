#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    Harl harl;

    if (argc == 2) {
        std::string str(argv[1]);
        std::string arr[4] = {
            "DEBUG",
            "INFO",
            "WARNING",
            "ERROR"
        };
        int i = 0;
        while (i < 4 && str != arr[i])
            i++;
        switch (i) {
            case 0:
                std::cout << "[ DEBUG ]" << std::endl;
                harl.complain("DEBUG");
                std::cout << std::endl;
                __attribute__ ((fallthrough));
            case 1:
                std::cout << "[ INFO ]" << std::endl;
                harl.complain("INFO");
                std::cout << std::endl;
                __attribute__ ((fallthrough));
            case 2:
                std::cout << "[ WARNING ]" << std::endl;
                harl.complain("WARNING");
                std::cout << std::endl;
                __attribute__ ((fallthrough));
            case 3:
                std::cout << "[ ERROR ]" << std::endl;
                harl.complain("ERROR");
                std::cout << std::endl;
                break;
            default:
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
                break;
        }
    }
    return (0);
}
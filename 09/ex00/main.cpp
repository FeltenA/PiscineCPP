#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2)
        std::cout << "Error: could not open file." << std::endl;
    else if (argc > 2)
        std::cout << "Error: too many arguments." << std::endl;
    else {
        try {
            BitcoinExchange exchange("./data.csv");
            exchange.evaluateFile(argv[1]);
        }
        catch(const BitcoinExchange::CouldNotOpenFile& e) {
            std::cout << e.what() << std::endl;
        }
        catch(const std::exception& e) {
            (void)e;
            std::cout << "Error: Parsing error." << std::endl;
        }
    }

    return (1);
}
#include "BitcoinExchange.hpp"
#include <iostream>

int main() {
    try {
        BitcoinExchange exchange("./data.csv");
        exchange.evaluateFile("./input.txt");
    }
    catch(const std::exception& e) {
        (void)e;
        std::cout << "Parsing error" << std::endl;
    }

    return (1);
}
#include "BitcoinExchange.hpp"

int main() {
    BitcoinExchange exchange("./data.csv");

    exchange.evaluateFile("./input.txt");

    return (1);
}
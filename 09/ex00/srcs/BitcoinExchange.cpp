#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {

}

BitcoinExchange::BitcoinExchange(std::string file_name) {

}

BitcoinExchange::BitcoinExchange(BitcoinExchange& src) {
    *this = src;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& rhs) {
    if (this != &rhs)
        this->_prices = rhs.getPrices();
    return (*this);
}

std::map<std::string, float>& BitcoinExchange::getPrices(void) {
    return (this->_prices);
}

void BitcoinExchange::setPrices(std::map<std::string, float> prices) {
    this->_prices = prices;
}
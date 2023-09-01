#include "BitcoinExchange.hpp"

bool    check_is_number(std::string value) {
    std::string::const_iterator it = value.begin();
    while (it != value.end() && std::isdigit(*it))
        ++it;
    return (!value.empty() && it == value.end());
}

bool    check_month(std::string month) {
    if (month.size() > 2)
        return (0);
    int value = atoi(month.c_str());
    if (value > 12)
        return (0);
    return (1);
}

bool    check_date(std::string date) {
    size_t pos = date.find('-');
    if (pos == std::string::npos)
        return (0);
    std::string month = date.substr(0, pos);
    if (!check_is_number(month))
        return (0);
    date.erase(0, pos + 1);
    pos = date.find('-');
    if (pos == std::string::npos)
        return (0);
    value = date.substr(0, pos);
    if (!check_is_number(value) || !check_month(value))
        return (0);
}

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
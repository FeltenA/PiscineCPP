#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

bool    is_space(char c) {
    return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v');
}

bool    is_empty(std::string line) {
    int len = line.size();
    int i = 0;
    while (i < len) {
        if (!is_space(line[i]))
            return (0);
        i++;
    }
    return (1);
}

bool    check_is_float(std::string value) {
    int point = 0;
    std::string::const_iterator it = value.begin();
    while (it != value.end() && (std::isdigit(*it) || *it == '.')) {
        if (*it == '.')
            point++;
        ++it;
    }
    return (!value.empty() && it == value.end() && point < 2);
}

bool    check_is_int(std::string value) {
    std::string::const_iterator it = value.begin();
    while (it != value.end() && std::isdigit(*it))
        ++it;
    return (!value.empty() && it == value.end());
}

bool    check_month(std::string month) {
    if (month.size() > 2)
        return (0);
    int value = atoi(month.c_str());
    if (value > 12 || value < 1)
        return (0);
    return (1);
}

bool    check_day(std::string sday, std::string smonth, std::string syear) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (sday.size() > 2)
        return (0);
    int day = atoi(sday.c_str());
    int month = atoi(smonth.c_str());
    int year = atoi(syear.c_str());
    if (month == 2 && (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))) {
        if (day < 1 || day > 29)
            return (0);
    }
    else {
        if (day < 1 || day > days[month - 1])
            return (0);
    }
    return (1);
}

bool    check_date(std::string date) {
    size_t pos = date.find('-');
    if (pos == std::string::npos)
        return (0);
    std::string year = date.substr(0, pos);
    if (!check_is_int(year))
        return (0);
    date.erase(0, pos + 1);
    pos = date.find('-');
    if (pos == std::string::npos)
        return (0);
    std::string month = date.substr(0, pos);
    if (!check_is_int(month) || !check_month(month))
        return (0);
    date.erase(0, pos + 1);
    pos = date.size();
    std::string day = date.substr(0, pos);
    if (!check_is_int(day) || !check_day(day, month, year))
        return (0);
    return (1);
}

BitcoinExchange::BitcoinExchange(void) {

}

BitcoinExchange::BitcoinExchange(std::string file_name) {
    std::ifstream file(file_name);
    std::string line;
    std::string date;
    size_t pos;
    float value;

    if (!file.is_open())
        throw std::exception();
    std::getline(file, line);
    while (file) {
        std::getline(file, line);
        if (is_empty(line))
            continue;
        pos = line.find(',');
        if (pos == std::string::npos)
            throw std::exception();
        date = line.substr(0, pos);
        line.erase(0, pos + 1);
        if (!check_date(date) || !check_is_float(line))
            throw std::exception();
        value = std::atof(line.c_str());
        this->_prices.insert({date, value});
    }
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

void BitcoinExchange::setPrices(std::map<std::string, float>& prices) {
    this->_prices = prices;
}

void BitcoinExchange::evaluate(std::string date, float value) {
    if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }
    else if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return;
    }
    else if (!check_date(date)) {
        std::cout << "Error: not a valid date." << std::endl;
        return;
    }
    std::string closestDate = this->getClosestLowerDate(date);
    if (closestDate.empty()) {
        std::cout << "Error: no closest lower date." << std::endl;
        return;
    }
    std::cout << date << " => " << value << " = " << value * this->_prices[closestDate] << std::endl;
}
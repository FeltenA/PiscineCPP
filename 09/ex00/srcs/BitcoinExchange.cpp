#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

bool    check_is_float(std::string value) {
    int point = 0;
    std::string::const_iterator it = value.begin();
    if (*it == '-' || *it == '+')
        it++;
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
    int value = std::atoi(month.c_str());
    if (value > 12 || value < 1)
        return (0);
    return (1);
}

bool    check_day(std::string sday, std::string smonth, std::string syear) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (sday.size() > 2)
        return (0);
    int day = std::atoi(sday.c_str());
    int month = std::atoi(smonth.c_str());
    int year = std::atoi(syear.c_str());
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
    std::ifstream input_file(file_name.c_str());
    std::string line;
    std::string date;
    size_t pos;
    float value;

    if (!input_file.is_open())
        throw CouldNotOpenFile();
    std::getline(input_file, line);
    while (std::getline(input_file, line)) {
        if (line.find_first_not_of(" \f\n\r\t\v") == std::string::npos)
            continue;
        pos = line.find(',');
        if (pos == std::string::npos)
            throw std::exception();
        date = line.substr(0, pos);
        line.erase(0, pos + 1);
        if (!check_date(date) || !check_is_float(line))
            throw std::exception();
        value = std::atof(line.c_str());
        this->_prices[date] = value;
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
    if (!check_date(date)) {
        std::cout << "Error: not a valid date." << std::endl;
        return;
    }
    else if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }
    else if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return;
    }
    std::map<std::string, float>::const_iterator it = this->_prices.find(date);
    if (it == this->_prices.end()) {
        it = this->_prices.upper_bound(date);
        if (it == this->_prices.begin()) {
            std::cout << "Error: no closest lower date." << std::endl;
            return;
        }
        it--;
    }
    std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

std::string& trim(std::string& str) {
    str.erase(0, str.find_first_not_of(" \f\n\r\t\v"));
    str.erase(str.find_last_not_of(" \f\n\r\t\v") + 1);
    return (str);
}

void BitcoinExchange::evaluateFile(std::string file_name) {
    std::ifstream input_file(file_name.c_str());
    std::string line;
    std::string date;
    size_t pos;
    float value;

    if (!input_file.is_open())
        throw CouldNotOpenFile();
    while (std::getline(input_file, line)) {
        if (line.find_first_not_of(" \f\n\r\t\v") == std::string::npos)
            continue;
        pos = line.find('|');
        if (pos == std::string::npos) {
            std::cout << "Error: bad input. => " << line << std::endl;
            continue;
        }
        date = line.substr(0, pos);
        date = trim(date);
        line = trim(line.erase(0, pos + 1));
        if (!check_is_float(line)) {
            std::cout << "Error: value not valid." << std::endl;
            continue;
        }
        value = std::atof(line.c_str());
        this->evaluate(date, value);
    }
}

const char* BitcoinExchange::CouldNotOpenFile::what() const throw() {
    return ("Error: could not open file.");
}
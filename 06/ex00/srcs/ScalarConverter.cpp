#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <math.h>

int isChar(std::string &literal) {
    if ((literal.size() == 3 && literal[0] == '\'' && literal[2] == '\''))
        return (1);
    return (0);
}

int isInt(std::string &literal) {
    int  i = 0;

    if (literal[i] == '+' || literal[i] == '-')
        i++;
    while (literal[i]) {
        if (!std::isdigit(literal[i]))
            return (0);
        i++;
    }
    return (1);
}

int isDouble(std::string &literal) {
    int i = 0;
    int dot = 0;
    int exp = 0;

    if (literal == "inf" || literal == "+inf" || literal == "-inf" || literal == "nan")
        return (1);
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    while (literal[i]) {
        if (!std::isdigit(literal[i]) && literal[i] != 'e' && literal[i] != 'E' && literal[i] != '.')
            return (0);
        else if (literal[i] == '.')
            dot++;
        else if (literal[i] == 'e' || literal[i] == 'E') {
            i++;
            exp++;
            if (literal[i] && (literal[i] == '+' || literal[i] == '-'))
                i++;
            continue ;
        }
        if (literal[i])
            i++;
    }
    if (dot > 1 || exp > 1)
        return (0);
    return (1);
}

int isFloat(std::string &literal) {
    int i = 0;
    int dot = 0;
    int exp = 0;

    if (literal == "inff" || literal == "+inff" || literal == "-inff" || literal == "nanf")
        return (1);
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    while (literal[i]) {
        if ((literal[i] == 'f' || literal[i] == 'F') && literal[i + 1] == 0)
            break ;
        if (!std::isdigit(literal[i]) && literal[i] != 'e' && literal[i] != 'E' && literal[i] != '.')
            return (0);
        else if (literal[i] == '.')
            dot++;
        else if (literal[i] == 'e' || literal[i] == 'E') {
            i++;
            exp++;
            if (literal[i] && (literal[i] == '+' || literal[i] == '-'))
                i++;
            continue ;
        }
        if (literal[i])
            i++;
    }
    if (dot > 1 || exp > 1)
        return (0);
    return (1);
}

void ScalarConverter::convert(std::string &literal) {
    long long int   iVal;
    char            cVal;
    double          dVal;
    float           fVal;

    if (isChar(literal)) {
        cVal = literal[1];
        iVal = static_cast<int>(cVal);
        fVal = static_cast<float>(cVal);
        dVal = static_cast<double>(cVal);
    }
    else if (isInt(literal)) {
        iVal = std::strtoll(literal.c_str(), 0, 10);
        if (iVal < std::numeric_limits<char>::max() && iVal > std::numeric_limits<char>::min())
            cVal = static_cast<char>(iVal);
        fVal = static_cast<float>(iVal);
        dVal = static_cast<double>(iVal);
    }
    else if (isDouble(literal)) {
        dVal = std::strtod(literal.c_str(), 0);
        fVal = static_cast<float>(dVal);
        if (dVal <= std::numeric_limits<int>::max() && dVal >= std::numeric_limits<int>::min())
            iVal = static_cast<char>(dVal);
        if (dVal <= std::numeric_limits<char>::max() && dVal >= std::numeric_limits<char>::min())
            cVal = static_cast<char>(dVal);
    }
    else if (isFloat(literal)) {
        fVal = std::strtof(literal.c_str(), 0);
        dVal = static_cast<double>(fVal);
        if (fVal <= std::numeric_limits<int>::max() && fVal >= std::numeric_limits<int>::min())
            iVal = static_cast<char>(fVal);
        if (fVal <= std::numeric_limits<char>::max() && fVal >= std::numeric_limits<char>::min())
            cVal = static_cast<char>(fVal);
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }

    if (iVal <= std::numeric_limits<char>::max() && iVal >= std::numeric_limits<char>::min()
        && dVal <= std::numeric_limits<char>::max() && dVal >= std::numeric_limits<char>::min()) {
        if (std::isprint(cVal))
            std::cout << "char: " << "\'" << cVal << "\'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    
    if (iVal <= std::numeric_limits<int>::max() && iVal >= std::numeric_limits<int>::min()
        && dVal <= std::numeric_limits<int>::max() && dVal >= std::numeric_limits<int>::min())
        std::cout << "int: " << iVal << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    if (fVal == iVal && (literal.size() <= 6 || ((literal[0] == '+' || literal[0] == '-') && literal.size() <= 7)))
        std::cout << "float: " << fVal << ".0f" << std::endl;
    else
        std::cout << "float: " << fVal << "f" << std::endl;
    if (dVal == iVal && (literal.size() <= 6 || ((literal[0] == '+' || literal[0] == '-') && literal.size() <= 7)))
        std::cout << "float: " << dVal << ".0" << std::endl;
    else
        std::cout << "double: " << dVal << std::endl;
}
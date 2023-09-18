#include "RPN.hpp"
#include <exception>

RPN::RPN(void) {

}

RPN::RPN(RPN& src) {
    *this = src;
}

RPN::~RPN(void) {

}

RPN& RPN::operator=(RPN& rhs) {
    if (this != &rhs) {
        this->setPile(rhs.getPile());
    }
    return (*this);
}

std::stack<int>& RPN::getPile(void) {
    return (this->_pile);
}

void RPN::setPile(std::stack<int>& pile) {
    this->_pile = pile;
}

bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*');
}
#include <iostream>
int RPN::evaluateString(std::string str) {
    int first;
    int second;
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if ((i % 2 == 1 && str[i] != ' ') || (i % 2 == 0 && ((!is_digit(str[i]) && !is_operator(str[i])) || (is_operator(str[i]) && this->_pile.size() < 2))))
            throw std::exception();
        if (is_digit(str[i]))
            this->_pile.push(str[i] - 48);
        else if (str[i] == '+') {
            first = this->_pile.top();
            this->_pile.pop();
            second = this->_pile.top();
            this->_pile.pop();
            this->_pile.push(second + first);
        }
        else if (str[i] == '-') {
            first = this->_pile.top();
            this->_pile.pop();
            second = this->_pile.top();
            this->_pile.pop();
            this->_pile.push(second - first);
        }
        else if (str[i] == '/') {
            first = this->_pile.top();
            this->_pile.pop();
            second = this->_pile.top();
            this->_pile.pop();
            if (first == 0)
                throw std::exception();
            this->_pile.push(second / first);
        }
        else if (str[i] == '*') {
            first = this->_pile.top();
            this->_pile.pop();
            second = this->_pile.top();
            this->_pile.pop();
            this->_pile.push(second * first);
        }
    }
    if (this->_pile.size() > 1)
        throw std::exception();
    first = this->_pile.top();
    this->_pile.pop();
    return (first);
}
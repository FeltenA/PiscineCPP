#include "Span.hpp"
#include <algorithm>

Span::Span(void) : _N(100) {

}

Span::Span(const Span& src) : _N(src.getN()) {
    this->_list.insert(this->_list.begin(), src.getList().begin(), src.getList().end());
}

Span::Span(unsigned int N) : _N(N) {

}

Span::~Span(void) {

}

Span& Span::operator=(const Span& rhs) {
    if (this != &rhs) {
        if (rhs.getList().size() > this->_N)
            throw std::exception();
        this->_list.clear();
        this->_list.insert(this->_list.begin(), rhs.getList().begin(), rhs.getList().end());
    }
    return (*this);
}

unsigned int Span::getN(void) const {
    return (this->_N);
}

const std::vector<int>& Span::getList(void) const {
    return (this->_list);
}

void Span::addNumber(int num) {
    if (this->_list.size() + 1 > this->_N)
        throw std::exception();
    this->_list.push_back(num);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) + this->_list.size() > this->_N)
        throw std::exception();
    this->_list.insert(this->_list.end(), begin, end);
}

int Span::longestSpan(void) {
    if (this->_list.size() < 2)
        throw std::exception();
    return (*std::max_element(this->_list.begin(), this->_list.end())
            - *std::min_element(this->_list.begin(), this->_list.end()));
}

int Span::shortestSpan(void) {
    std::vector<int>::iterator it;
    int span = -1;

    if (this->_list.size() < 2)
        throw std::exception();
    std::vector<int> slist = this->_list;
    std::sort(slist.begin(), slist.end());
    it = slist.begin();
    span = *(it + 1) - *it;
    for (it = slist.begin() + 1; it != slist.end() - 1; it++) {
        if (*(it + 1) - *it < span)
            span = *(it + 1) - *it;
    }
    return (span);
}
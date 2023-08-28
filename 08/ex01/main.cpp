#include "Span.hpp"
#include <iostream>

int main(void) {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span test = Span(15000);
    std::vector<int> list;
    for (int i = 0; i < 15000; i++)
        list.push_back(i);
    test.addRange(list.begin(), list.end());
    std::cout << test.shortestSpan() << std::endl;
    std::cout << test.longestSpan() << std::endl;
    return 0;
}
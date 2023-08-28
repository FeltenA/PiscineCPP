#include "MutantStack.hpp"
#include <iostream>

int main(void) {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    MutantStack<char> test;
    test.push('t');
    test.push('e');
    test.push('s');
    test.push('t');
    MutantStack<char> test2(test);
    MutantStack<char>::iterator testit = test2.begin();
    MutantStack<char>::iterator testite = test2.end();
    while (testit != testite)
    {
        std::cout << *testit << std::endl;
        ++testit;
    }
    return 0;
}
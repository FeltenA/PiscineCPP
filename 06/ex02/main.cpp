#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base*   generate(void) {
    std::srand((unsigned) time(0));
    int nbr = ((int) (rand() % 3));
    if (nbr == 0)
        return (new A());
    else if (nbr == 1)
        return (new B());
    else if (nbr == 2)
        return (new C());
    return (0);
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e) {
        try {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::exception &e) {
            try {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::exception &e) {
                std::cout << "unknown" << std::endl;
            }
        }
    }
}

int main(void) {
    Base* base = generate();
    identify(base);
    identify(*base);
    delete base;

    return (0);
}
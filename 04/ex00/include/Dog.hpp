#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : Animal {
    Dog(void);
    Dog(std::string type);
    ~Dog(void);

    Dog& operator=(const Dog& src);
};

#endif
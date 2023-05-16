#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog") {

}

Dog::Dog(const Dog& src) {
    *this = src;
}

Dog::~Dog(void) {

}

Dog& Dog::operator=(const Dog& rhs) {
    if (this != &rhs)
        Animal::operator=(rhs);
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "Wouf!" << std::endl;
}
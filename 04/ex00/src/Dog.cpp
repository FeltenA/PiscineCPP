#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    if (this != &rhs)
        Animal::operator=(rhs);
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "Wouf!" << std::endl;
}
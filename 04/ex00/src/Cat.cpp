#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src) {
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void) {
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    if (this != &rhs)
        Animal::operator=(rhs);
    return (*this);
}

void Cat::makeSound(void) const {
    std::cout << "Miaou!" << std::endl;
}
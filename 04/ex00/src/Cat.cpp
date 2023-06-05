#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat") {

}

Cat::Cat(const Cat& src) : Animal(src) {

}

Cat::~Cat(void) {

}

Cat& Cat::operator=(const Cat& rhs) {
    if (this != &rhs)
        Animal::operator=(rhs);
    return (*this);
}

void Cat::makeSound(void) const {
    std::cout << "Miaou!" << std::endl;
}
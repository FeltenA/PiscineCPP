#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : type("animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& src) {
    std::cout << "Animal constructor called" << std::endl;
    *this = src;
}

Animal::~Animal(void) {
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
    if (this != &rhs)
        this->setType(rhs.getType());
    return (*this);
}

std::string Animal::getType(void) const {
    return (this->type);
}

void Animal::setType(std::string type) {
    this->type = type;
}

void Animal::makeSound(void) const {
    std::cout << "An animal sound" << std::endl;
}
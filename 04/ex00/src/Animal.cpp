#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : type("animal") {

}

Animal::Animal(std::string type) : type(type) {

}

Animal::Animal(const Animal& src) {
    *this = src;
}

Animal::~Animal(void) {

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
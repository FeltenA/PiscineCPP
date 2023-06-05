#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : type("animal") {

}

WrongAnimal::WrongAnimal(std::string type) : type(type) {

}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
    *this = src;
}

WrongAnimal::~WrongAnimal(void) {

}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
    if (this != &rhs)
        this->setType(rhs.getType());
    return (*this);
}

std::string WrongAnimal::getType(void) const {
    return (this->type);
}

void WrongAnimal::setType(std::string type) {
    this->type = type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "An animal sound" << std::endl;
}
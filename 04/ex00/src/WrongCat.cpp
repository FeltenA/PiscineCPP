#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("Cat") {

}

WrongCat::WrongCat(const WrongCat& src) {
    *this = src;
}

WrongCat::~WrongCat(void) {

}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
    if (this != &rhs)
        WrongAnimal::operator=(rhs);
    return (*this);
}

void WrongCat::makeSound(void) const {
    std::cout << "Miaou!" << std::endl;
}
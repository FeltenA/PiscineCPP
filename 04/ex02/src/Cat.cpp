#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src) {
    std::cout << "Cat constructor called" << std::endl;
    this->_brain = new Brain();
    *(this->_brain) = *src.getBrain();
}

Cat::~Cat(void) {
    std::cout << "Cat destructor called" << std::endl;
    if (this->_brain)
        delete this->_brain;
}

Cat& Cat::operator=(const Cat& rhs) {
    if (this != &rhs) {
        Animal::operator=(rhs);
        if (!this->_brain)
            this->_brain = new Brain();
        *(this->_brain) = *rhs.getBrain();
    }
    return (*this);
}

void Cat::makeSound(void) const {
    std::cout << "Miaou!" << std::endl;
}

Brain* Cat::getBrain(void) const {
    return (this->_brain);
}

void Cat::setBrain(Brain* brain) {
    if (this->_brain)
        delete this->_brain;
    this->_brain = brain;
}
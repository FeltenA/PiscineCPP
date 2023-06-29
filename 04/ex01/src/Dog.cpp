#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src) {
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
    *(this->_brain) = *src.getBrain();
}

Dog::~Dog(void) {
    std::cout << "Cat destructor called" << std::endl;
    if (this->_brain)
        delete this->_brain;
}

Dog& Dog::operator=(const Dog& rhs) {
    if (this != &rhs) {
        Animal::operator=(rhs);
        if (!this->_brain)
            this->_brain = new Brain();
        *(this->_brain) = *rhs.getBrain();
    }
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "Wouf!" << std::endl;
}

Brain* Dog::getBrain(void) const {
    return (this->_brain);
}

void Dog::setBrain(Brain* brain) {
    if (this->_brain)
        delete this->_brain;
    this->_brain = brain;
}
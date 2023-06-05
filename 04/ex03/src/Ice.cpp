#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {

}

Ice::Ice(const Ice& src) : AMateria("ice") {
    (void)src;
}

Ice::~Ice(void) {

}

Ice& Ice::operator=(const Ice& rhs) {
    (void)rhs;
    return (*this);
}

AMateria* Ice::clone(void) const {
    return (new Ice());
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
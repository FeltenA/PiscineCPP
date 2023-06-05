#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {

}

Cure::Cure(const Cure& src) : AMateria("cure") {
    (void)src;
}

Cure::~Cure(void) {

}

Cure& Cure::operator=(const Cure& rhs) {
    (void)rhs;
    return (*this);
}

AMateria* Cure::clone(void) const {
    return (new Cure());
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
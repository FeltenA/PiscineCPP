#include "AMateria.hpp"

AMateria::AMateria(void) : type("default") {

}

AMateria::AMateria(const std::string& type) : type(type) {

}

AMateria::AMateria(const AMateria& src) : type(src.type) {

}

AMateria::~AMateria(void) {

}

AMateria& AMateria::operator=(const AMateria& rhs) {
    (void)rhs;
    return (*this);
}

const std::string& AMateria::getType(void) const {
    return (this->type);
}

void AMateria::use(ICharacter& target) {
    (void)target;
}
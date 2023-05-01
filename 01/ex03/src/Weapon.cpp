#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
    return;
}

Weapon::~Weapon(void) {
    return;
}

void    Weapon::setType(std::string type) {
    this->type = type;
}

std::string Weapon::getType(void) {
    return (this->type);
}
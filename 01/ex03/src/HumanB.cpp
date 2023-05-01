#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(0) {
    return;
}

HumanB::~HumanB(void) {
    return;
}

void    HumanB::attack(void) {
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}
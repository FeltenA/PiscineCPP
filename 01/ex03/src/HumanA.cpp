#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
    return;
}

HumanA::~HumanA(void) {
    return;
}

void    HumanA::attack(void) {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
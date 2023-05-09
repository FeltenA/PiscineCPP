#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : FragTrap("default_clap_name"), _name("default") {
    this->setEnergyPoints(50);
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name + "_clap_name") {
    this->setEnergyPoints(50);
    this->_name = name;
    std::cout << "DiamondTrap " << this->getName() << " constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap " << this->getName() << " destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << "I am " << this->_name << " and " << this->ClapTrap::getName() << "!" << std::endl;
}
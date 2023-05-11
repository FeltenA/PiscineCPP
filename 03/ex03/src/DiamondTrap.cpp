#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name"), _name("default") {
    this->setEnergyPoints(50);
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name) {
    this->setEnergyPoints(50);
    std::cout << "DiamondTrap " << this->getName() << " constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap " << this->getName() << " destructor called" << std::endl;
}

std::string DiamondTrap::getName(void) const {
    return (this->_name);
}

void DiamondTrap::setName(std::string name) {
    this->_name = name;
}

void DiamondTrap::attack(const std::string& target) {
    this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << "I am " << this->_name << " and " << this->ClapTrap::getName() << "!" << std::endl;
}
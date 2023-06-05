#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) {
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap " << this->getName() << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
    *this = src;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap " << this->getName() << " destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return (*this);
}

void ScavTrap::attack(const std::string& target) {
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0) {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target;
        std::cout << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    }
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode!" << std::endl;
}
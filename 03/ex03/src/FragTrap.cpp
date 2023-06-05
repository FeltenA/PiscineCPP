#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) {
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "FragTrap " << this->getName() << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
    std::cout << "FragTrap " << this->getName() << " copy constructor called" << std::endl;
    *this = src;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap " << this->getName() << " destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return (*this);
}

void FragTrap::attack(const std::string& target) {
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0) {
        std::cout << "FragTrap " << this->getName() << " attacks " << target;
        std::cout << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    }
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->getName() << " wants a high five!" << std::endl;
}
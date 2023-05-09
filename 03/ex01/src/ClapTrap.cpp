#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src) {
    if (&src != this) {
        this->_name = src.getName();
        this->_hitPoints = src.getHitPoints();
        this->_energyPoints = src.getEnergyPoints();
        this->_attackDamage = src.getAttackDamage();
    }
    return (*this);
}

std::string ClapTrap::getName(void) const {
    return (this->_name);
}

int ClapTrap::getHitPoints(void) const {
    return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const {
    return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const {
    return (this->_attackDamage);
}

void ClapTrap::setName(std::string name) {
    this->_name = name;
}

void ClapTrap::setHitPoints(int hitPoints) {
    this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
    this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage) {
    this->_attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        std::cout << "ClapTrap " << this->_name << " attacks " << target;
        std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints - amount < 0)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        std::cout << "ClapTrap " << this->_name << " repairs itself by " << amount << " hit points!" << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints--;
    }
}
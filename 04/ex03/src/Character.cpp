#include "Character.hpp"

Character::Character(void) : _name("default") {
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = 0;
}

Character::Character(const std::string& name) : _name(name) {
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = 0;
}

Character::Character(const Character& src) : _name(src.getName()) {
    AMateria* lst = src.getInventory();
    for (int i = 0; i < 4; i++) {
        if (lst + i)
            this->_inventory[i] = (lst + i)->clone();
        else
            this->_inventory[i] = 0;
    }
}

Character::~Character(void) {
    for (int i = 0; i < 4; i++)
        if (this->_inventory[i])
            delete this->_inventory[i];
}

Character& Character::operator=(const Character& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i])
                delete this->_inventory[i];
        }
        AMateria* lst = rhs.getInventory();
        for (int i = 0; i < 4; i++) {
            if (lst + i)
                this->_inventory[i] = (lst + i)->clone();
            else
                this->_inventory[i] = 0;
        }
    }
    return (*this);
}

const std::string& Character::getName(void) const {
    return (this->_name);
}

AMateria* Character::getInventory(void) const {
    return ((AMateria*)this->_inventory);
}

void Character::setInventory(AMateria* inventory[4]) {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = inventory[i];
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!this->_inventory[i]) {
            this->_inventory[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && this->_inventory[idx]) {
        delete this->_inventory[idx];
        this->_inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
        this->_inventory[idx]->use(target);
}
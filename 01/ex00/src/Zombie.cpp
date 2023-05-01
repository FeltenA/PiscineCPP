#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name(name) {
    return;
}

Zombie::~Zombie(void) {
    std::cout << this->name << ": Destructor called" << std::endl;
    return;
}

void    Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}
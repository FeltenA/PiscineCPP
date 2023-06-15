#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
    FragTrap def;
    ScavTrap bob("bob");
    DiamondTrap dia("dia");

    std::cout << "hitpoints: " << dia.getHitPoints() << ", energy: " << dia.getEnergyPoints() << ", attack: " << dia.getAttackDamage() << std::endl;
    def.attack(bob.getName());
    def.takeDamage(bob.getAttackDamage());
    def.takeDamage(20);
    def.beRepaired(10);
    bob.attack("test");
    bob.beRepaired(10);
    bob.setEnergyPoints(0);
    bob.beRepaired(10);
    dia.attack("test");
    dia.whoAmI();
    DiamondTrap dia2(dia);
    std::cout << "hitpoints: " << dia2.getHitPoints() << ", energy: " << dia2.getEnergyPoints() << ", attack: " << dia2.getAttackDamage() << std::endl;
    dia2.attack("test2");
    dia2.whoAmI();

    return (0);
}
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
    FragTrap def;
    ScavTrap bob("bob");
    DiamondTrap dia("dia");

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

    return (0);
}
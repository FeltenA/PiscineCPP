#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    FragTrap def;
    ScavTrap bob("bob");

    def.attack(bob.getName());
    def.takeDamage(bob.getAttackDamage());
    def.takeDamage(20);
    def.beRepaired(10);
    bob.attack("test");
    bob.beRepaired(10);
    bob.setEnergyPoints(0);
    bob.beRepaired(10);

    return (0);
}
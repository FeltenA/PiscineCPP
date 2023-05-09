#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        ~DiamondTrap(void);

        void attack(const std::string& target);
        void whoAmI(void);

    private:
        std::string _name;
};

#endif
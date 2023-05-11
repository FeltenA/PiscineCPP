#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        ~DiamondTrap(void);

        std::string getName(void) const;
        void setName(std::string name);

        void attack(const std::string& target);
        void whoAmI(void);

    private:
        std::string _name;
};

#endif
#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& src);
        ~DiamondTrap(void);
        DiamondTrap& operator=(const DiamondTrap& rhs);

        std::string getName(void) const;
        void setName(std::string name);

        void attack(const std::string& target);
        void whoAmI(void);

    private:
        std::string _name;
};

#endif
#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& src);
        ~ScavTrap(void);
        ScavTrap& operator=(const ScavTrap& rhs);

        void attack(const std::string& target);
        void guardGate(void);
};

#endif
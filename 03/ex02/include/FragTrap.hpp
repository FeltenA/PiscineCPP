#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap& src);
        ~FragTrap(void);
        FragTrap& operator=(const FragTrap& rhs);

        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
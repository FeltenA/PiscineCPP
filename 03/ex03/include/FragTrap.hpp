#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

    public:
        FragTrap(void);
        FragTrap(std::string name);
        ~FragTrap(void);

        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
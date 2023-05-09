#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {

    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ~ClapTrap(void);
        ClapTrap& operator=(const ClapTrap &src);

        std::string getName(void) const;
        int getHitPoints(void) const;
        int getEnergyPoints(void) const;
        int getAttackDamage(void) const;
        void setName(std::string name);
        void setHitPoints(int hitPoint);
        void setEnergyPoints(int energyPoints);
        void setAttackDamage(int attackDamage);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
};

#endif
#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"

class Character : public ICharacter {

    public:
        Character(void);
        Character(const std::string& name);
        Character(const Character& src);
        ~Character(void);

        Character& operator=(const Character& rhs);

        std::string const & getName() const;
        AMateria* getInventory(void) const;
        void setInventory(AMateria* inventory[4]);

        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

    private:
        const std::string _name;
        AMateria* _inventory[4];
};

#endif
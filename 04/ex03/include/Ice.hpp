#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria {

    public:
        Ice(void);
        Ice(const Ice& src);
        ~Ice(void);

        Ice& operator=(const Ice& rhs);

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
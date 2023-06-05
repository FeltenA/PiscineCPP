#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria {

    public:
        Cure(void);
        Cure(const Cure& src);
        ~Cure(void);

        Cure& operator=(const Cure& rhs);

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
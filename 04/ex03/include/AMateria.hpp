#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>
class AMateria;
#include "ICharacter.hpp"

class AMateria {
    
    protected:
        const std::string type;

    public:
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(const AMateria& src);
        virtual ~AMateria(void);

        AMateria& operator=(const AMateria& rhs);

        std::string const & getType() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

};

#endif
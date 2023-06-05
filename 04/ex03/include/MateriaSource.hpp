#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource& src);
        ~MateriaSource(void);

        MateriaSource& operator=(const MateriaSource& rhs);

        AMateria* getMaterias(void) const;
        void setMaterias(AMateria* materias[4]);

        void learnMateria(AMateria* m);
        AMateria* createMateria(const std::string& type);

    private:
        AMateria* _materias[4];
};

#endif
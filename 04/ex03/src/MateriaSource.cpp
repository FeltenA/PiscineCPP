#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    for (int i = 0; i < 4; i++)
        this->_materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
    AMateria* lst = src.getMaterias();
    for (int i = 0; i < 4; i++) {
        if (lst + i)
            this->_materias[i] = (lst + i)->clone();
        else
            this->_materias[i] = 0;
    }
}

MateriaSource::~MateriaSource(void) {
    for (int i = 0; i < 4; i++)
        if (this->_materias[i])
            delete this->_materias[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; i++) {
            if (this->_materias[i])
                delete this->_materias[i];
        }
        AMateria* lst = rhs.getMaterias();
        for (int i = 0; i < 4; i++) {
            if (lst + i)
                this->_materias[i] = (lst + i)->clone();
            else
                this->_materias[i] = 0;
        }
    }
    return (*this);
}

AMateria* MateriaSource::getMaterias(void) const {
    return ((AMateria*) this->_materias);
}

void MateriaSource::setMaterias(AMateria* materias[4]) {
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i])
            delete this->_materias[i];
    }
    for (int i = 0; i < 4; i++)
        this->_materias[i] = materias[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!this->_materias[i]) {
            this->_materias[i] = m;
            break ;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i]->getType() == type)
            return (this->_materias[i]->clone());
    }
    return (0);
}
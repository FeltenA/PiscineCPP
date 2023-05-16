#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal {
    
    public:
        Dog(void);
        Dog(const Dog& src);
        ~Dog(void);

        Dog& operator=(const Dog& rhs);

        void makeSound(void) const;
};

#endif
#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    
    public:
        Dog(void);
        Dog(const Dog& src);
        ~Dog(void);

        Dog& operator=(const Dog& rhs);

        void makeSound(void) const;
        Brain* getBrain(void) const;
        void setBrain(Brain* brain);

    private:
        Brain* _brain;
};

#endif
#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

    public:
        Cat(void);
        Cat(const Cat& src);
        ~Cat(void);

        Cat& operator=(const Cat& src);

        void makeSound(void) const;
        Brain* getBrain(void) const;
        void setBrain(Brain* brain);

    private:
        Brain* _brain;
};

#endif
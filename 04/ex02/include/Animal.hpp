#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {

    public:
        Animal(void);
        Animal(std::string type);
        Animal(const Animal& src);
        virtual ~Animal(void) = 0;

        Animal& operator=(const Animal& rhs);

        std::string getType(void) const;
        void setType(std::string type);

        virtual void makeSound(void) const = 0;

    protected:
        std::string type;
};

#endif
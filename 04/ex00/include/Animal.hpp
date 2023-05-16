#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {

    public:
        Animal(void);
        Animal(std::string type);
        Animal(const Animal& src);
        virtual ~Animal(void);

        Animal& operator=(const Animal& rhs);

        std::string getType(void) const;
        void setType(std::string type);

        virtual void makeSound(void) const;

    protected:
        std::string type;
};

#endif
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {

    public:
        Animal(void);
        Animal(std::string type);
        ~Animal(void);

        Animal& operator=(const Animal& src);

        std::string getType(void) const;
        void setType(std::string type);

    protected:
        std::string type;
};

#endif
#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>

class WrongAnimal {

    public:
        WrongAnimal(void);
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& src);
        ~WrongAnimal(void);

        WrongAnimal& operator=(const WrongAnimal& rhs);

        std::string getType(void) const;
        void setType(std::string type);

        void makeSound(void) const;

    protected:
        std::string type;
};

#endif
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {

    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);

        void announce( void );
        void set_name(std::string name);
        std::string get_name(void);

    private:
        std::string name;
};

#endif
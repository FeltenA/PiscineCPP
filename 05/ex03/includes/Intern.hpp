#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"

class Intern {

    public:
        Intern(void);
        Intern(const Intern& src);
        ~Intern(void);

        Intern& operator=(const Intern& rhs);

        AForm* makeForm(std::string name, std::string target);
};

#endif
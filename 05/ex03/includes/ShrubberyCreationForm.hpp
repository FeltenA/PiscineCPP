#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ~ShrubberyCreationForm(void);

        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

        std::string getTarget(void) const;

        void execute(Bureaucrat const & executor) const;

    private:
        const std::string _target;
};

#endif
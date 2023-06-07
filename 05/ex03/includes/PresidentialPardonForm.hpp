#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& src);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

        std::string getTarget(void) const;

        void execute(Bureaucrat const & executor) const;

    private:
        const std::string _target;
};

#endif
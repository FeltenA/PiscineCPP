#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& src);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

        std::string getTarget(void) const;

        void execute(Bureaucrat const & executor) const;

    private:
        const std::string _target;
};

#endif
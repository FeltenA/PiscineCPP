#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomy request", 72, 45), _target("default") {

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("robotomy request", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src.getName(), 72, 45), _target(src.getTarget()) {

}

RobotomyRequestForm::~RobotomyRequestForm(void) {

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    if (&rhs != this)
        AForm::operator=(rhs);
    return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const {
    return (this->_target);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!this->getSigned())
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else
    {
        std::srand((unsigned) time(0));
        if (!((int) (rand() % 2)))
            std::cout << this->_target << " has been robotomized" << std::endl;
        else
            std::cout << "Robotomy has failed" << std::endl;
    }
}

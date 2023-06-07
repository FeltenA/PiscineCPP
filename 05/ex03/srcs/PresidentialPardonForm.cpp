#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("robotomy request", 72, 5), _target("default") {

}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("robotomy request", 72, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src.getName(), 72, 5), _target(src.getTarget()) {

}

PresidentialPardonForm::~PresidentialPardonForm(void) {

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
    if (&rhs != this)
        AForm::operator=(rhs);
    return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const {
    return (this->_target);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!this->getSigned())
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}

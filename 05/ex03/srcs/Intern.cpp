#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {

}

Intern::Intern(const Intern& src) {
    (void)src;
}

Intern::~Intern(void) {

}

Intern& Intern::operator=(const Intern& rhs) {
    (void)rhs;
    return (*this);
}

AForm* makeShrubberyCreationForm(std::string target) {
    return (new ShrubberyCreationForm(target));
}

AForm* makeRobotomyRequestForm(std::string target) {
    return (new RobotomyRequestForm(target));
}

AForm* makePresidentialPardonForm(std::string target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target) {
    typedef AForm *(*fun)(std::string target);
    std::string list[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    fun functArray[3] = {
        &makeShrubberyCreationForm,
        &makeRobotomyRequestForm,
        &makePresidentialPardonForm
    };
    for (int i = 0; i < 3; i++) {
        if (name == list[i])
        {
            std::cout << "Intern creates " << list[i] << std::endl;
            return ((functArray[i])(target));
        }
    }
    std::cout << "Intern cannot create " << name << std::endl;
    return (NULL);
}

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

    AForm* pardon = new PresidentialPardonForm("pardon_target");
    AForm* robotomy = new RobotomyRequestForm("robotomy_target");
    AForm* shrubbery = new ShrubberyCreationForm("shrubbery_target");

    Bureaucrat test138("test138", 138);
    Bureaucrat test137("test137", 137);
    Bureaucrat test45("test45", 45);
    Bureaucrat test5("test5", 5);

    std::cout << std::endl << "-----------------------------------------" << std::endl;
    test5.executeForm(*shrubbery);
    test138.signForm(*shrubbery);
    test138.executeForm(*shrubbery);
    test137.executeForm(*shrubbery);

    std::cout << std::endl << "-----------------------------------------" << std::endl;
    test5.executeForm(*robotomy);
    test45.signForm(*robotomy);
    test137.executeForm(*robotomy);
    test45.executeForm(*robotomy);

    std::cout << std::endl << "-----------------------------------------" << std::endl;
    test5.executeForm(*pardon);
    test45.signForm(*pardon);
    test45.executeForm(*pardon);
    test5.executeForm(*pardon);

    delete  shrubbery;
    delete  robotomy;
    delete  pardon;

    return (0);
}

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {

    Intern test;

    AForm* testform = test.makeForm("test", "test_target");
    (void)testform;
    AForm* pardon = test.makeForm("presidential pardon", "pardon_target");
    AForm* robotomy = test.makeForm("robotomy request", "robotomy_target");
    AForm* shrubbery = test.makeForm("shrubbery creation", "shrubbery_target");

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
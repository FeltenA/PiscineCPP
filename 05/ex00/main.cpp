
#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat test("test", 0);
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat test("test", 151);
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat test("test", 1);

        std::cout << test << std::endl;
        test.incrementGrade();
        std::cout << test << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat test("test", 150);

        std::cout << test << std::endl;
        test.decrementGrade();
        std::cout << test << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
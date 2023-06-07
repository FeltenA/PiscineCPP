
#include "Bureaucrat.hpp"

int main(void) {
    try {
        Form test("test", 0, 12);
    }
    catch (Form::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form test("test", 151, 12);
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    Form form("testform", 12, 1);
    Bureaucrat bur("burtest", 13);

    bur.signForm(form);
    bur.incrementGrade();
    bur.signForm(form);
    
    return (0);
}
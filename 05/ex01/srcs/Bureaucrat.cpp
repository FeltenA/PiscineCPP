#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {

}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()), _grade(src.getGrade()) {

}

Bureaucrat::~Bureaucrat(void) {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    if (&rhs != this)
        this->_grade = rhs.getGrade();
    return (*this);
}

std::string Bureaucrat::getName(void) const {
    return (this->_name);
}

int Bureaucrat::getGrade(void) const {
    return (this->_grade);
}

void Bureaucrat::incrementGrade(void) {
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("The grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("The grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
    os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return (os);
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << *this << " signed " << form << std::endl;
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << *this << " couldn’t sign " << form << " because " << e.what() << "." << std::endl;
    }
}
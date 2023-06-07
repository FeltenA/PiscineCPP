#include "Form.hpp"

Form::Form(void) : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {

}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& src) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()) {

}

Form::~Form(void) {

}

Form& Form::operator=(const Form& rhs) {
    if (&rhs != this)
        this->_signed = rhs.getSigned();
    return (*this);
}

std::string Form::getName(void) const {
    return (this->_name);
}

bool Form::getSigned(void) const {
    return (this->_signed);
}

int Form::getGradeToSign(void) const {
    return (this->_gradeToSign);
}

int Form::getGradeToExec(void) const {
    return (this->_gradeToExec);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (!this->_signed) {
        if (bureaucrat.getGrade() > this->_gradeToSign)
            throw Form::GradeTooLowException();
        else
            this->_signed = true;
    }
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("The grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("The grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Form& rhs) {
    os << rhs.getName() << ", form signed " << rhs.getSigned() << ", form grade to sign " << rhs.getGradeToSign() << ", form grade to execute " << rhs.getGradeToExec() << ".";
    return (os);
}
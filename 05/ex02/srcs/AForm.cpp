#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {

}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()) {

}

AForm::~AForm(void) {

}

AForm& AForm::operator=(const AForm& rhs) {
    if (&rhs != this)
        this->_signed = rhs.getSigned();
    return (*this);
}

std::string AForm::getName(void) const {
    return (this->_name);
}

bool AForm::getSigned(void) const {
    return (this->_signed);
}

int AForm::getGradeToSign(void) const {
    return (this->_gradeToSign);
}

int AForm::getGradeToExec(void) const {
    return (this->_gradeToExec);
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (!this->_signed) {
        if (bureaucrat.getGrade() > this->_gradeToSign)
            throw AForm::GradeTooLowException();
        else
            this->_signed = true;
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return ("The grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("The grade is too low");
}

const char* AForm::NotSignedException::what() const throw() {
    return ("The form is not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs) {
    os << rhs.getName() << ", form signed " << rhs.getSigned() << ", form grade to sign " << rhs.getGradeToSign() << ", form grade to execute " << rhs.getGradeToExec() << ".";
    return (os);
}
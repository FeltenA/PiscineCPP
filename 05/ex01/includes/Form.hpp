#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    public:
        Form(void);
        Form(const std::string name, const int gradeToSign, const int gradeToExec);
        Form(const Form& src);
        ~Form(void);

        Form& operator=(const Form& rhs);

        std::string getName(void) const;
        bool getSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;

        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExec;
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif
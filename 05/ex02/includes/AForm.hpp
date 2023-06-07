#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

    public:
        AForm(void);
        AForm(const std::string name, const int gradeToSign, const int gradeToExec);
        AForm(const AForm& src);
        virtual ~AForm(void);

        AForm& operator=(const AForm& rhs);

        std::string getName(void) const;
        bool getSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;

        virtual void execute(Bureaucrat const & executor) const = 0;

        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NotSignedException : std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExec;
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif
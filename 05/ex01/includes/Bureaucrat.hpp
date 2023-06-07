#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {

    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& src);
        ~Bureaucrat(void);

        Bureaucrat& operator=(const Bureaucrat& rhs);

        std::string getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void);
        void decrementGrade(void);

        void signForm(Form& form);

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
        int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif
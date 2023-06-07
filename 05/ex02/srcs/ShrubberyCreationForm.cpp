#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shrubbery creation", 145, 137), _target("default") {

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("shrubbery creation", 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src.getName(), 145, 137), _target(src.getTarget()) {

}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    if (&rhs != this)
        AForm::operator=(rhs);
    return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const {
    return (this->_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!this->getSigned())
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else
    {
        std::ofstream file((this->_target + "_shrubbery").c_str(), std::ofstream::out);
        file << "                      ___" << std::endl;
        file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
        file << "             ,-'          __,,-- \\" << std::endl;
        file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
        file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
        file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
        file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
        file << "     (     ,-'                  `." << std::endl;
        file << "      `._,'     _   _             ;" << std::endl;
        file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
        file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
        file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
        file << "                \"Hb HH dF" << std::endl;
        file << "                 \"HbHHdF" << std::endl;
        file << "                  |HHHF" << std::endl;
        file << "                  |HHH|" << std::endl;
        file << "                  |HHH|" << std::endl;
        file << "                  |HHH|" << std::endl;
        file << "                  |HHH|" << std::endl;
        file << "                  dHHHb" << std::endl;
        file << "                .dFd|bHb.               o" << std::endl;
        file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
        file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
        file << "##########################################" << std::endl;
        file.close();
    }
}

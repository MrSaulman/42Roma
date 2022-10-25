#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form {
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
        virtual bool execute(Bureaucrat const &executor) const;
};

#endif
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), _target("")
{
    std::cout << "Costructor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "Costructor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "Destructor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj)
{
    std::cout << "Costructor Copy PresidentialPardonForm" << std::endl;
    *this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
    std::cout << "Assignation PresidentialPardonForm" << std::endl;
    if (this != &obj)
        this->_target = obj._target;
    return (*this);
}

bool PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSign())
    {
        throw Form::NotSignedException();
    }
    else if (executor.getGrade() > this->getGradeExecute())
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
        std::cout <<  "Tells us <" << this->_target << "> has been pardoned by Zafod Beeblebrox" << std::endl;
		return true;
    }
}

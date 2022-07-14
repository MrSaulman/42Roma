#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45), _target("")
{
    std::cout << "Costructor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "Costructor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "Destructor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj)
{
    std::cout << "Costructor Copy RobotomyRequestForm" << std::endl;
    *this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
    std::cout << "Assignation RobotomyRequestForm" << std::endl;
    if (this != &obj)
        this->_target = obj._target;
    return (*this);
}

bool RobotomyRequestForm::execute(Bureaucrat const &executor) const
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

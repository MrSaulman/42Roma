#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern Costructor" << std::endl;
}

Intern::Intern(const Intern &obj)
{
    std::cout << "Intern Copy Costructor" << std::endl;
    *this = obj;
}

Intern::~Intern(void)
{
    std::cout << "Intern Costructor" << std::endl;
}

Intern &Intern::operator=(Intern const &obj)
{
    if (this != &obj)
        *this = obj;
    return (*this);
}

Form* newShrubber(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

Form* newRoboto(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

Form* newPresident(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

typedef Form *(*makeF)(const std::string&);

Form* Intern::makeForm(std::string formName, std::string target) const
{
    Form		*ret = NULL;
	std::string	nameForm[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	Form		*form[3] = { new ShrubberyCreationForm( target ), new RobotomyRequestForm( target ), new PresidentialPardonForm( target ) };

	for (int i = 0; i < 3; i++) {

		if (nameForm[i] == formName) {

			std::cout << "Intern creates " << form[i]->getName() << "." << std::endl;
			ret = form[i];
		}
		else
			delete form[i];
	}
	if (!ret)
	{
        std::cout << "Nome form sconosciuto" << std::endl;
        return NULL;
    }
	return ret;
}

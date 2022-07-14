#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern interno;
	Bureaucrat burocrate("burocrazia!", 1);
	Form *legge = interno.makeForm("presidential pardon", "target");
	burocrate.signForm(*legge);
	burocrate.executeForm(*legge);
}
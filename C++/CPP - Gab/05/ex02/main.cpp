#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat Buro("Buro", 1);
    Bureaucrat Muro("Muro", 40);
    Bureaucrat Guro("Guro", 150);
    PresidentialPardonForm LeggePresidenziale("LeggePresidenziale"); //25,5
	ShrubberyCreationForm ShrubbForm("ShrubbForm");// 145, 137
    RobotomyRequestForm FormRobot("FormRobot");  // 72,45
    //Form Legge("Legge", 30, 50); interfaccia astratta non la fa istanziare 

    std::cout << "0" << std::endl;
    Buro.signForm(LeggePresidenziale); //deve andare
    std::cout << "1" << std::endl;
    Buro.executeForm(LeggePresidenziale); //deve andare
    std::cout << "2" << std::endl;
    Guro.signForm(ShrubbForm); //non deve andare
    std::cout << "3" << std::endl;
    Guro.executeForm(ShrubbForm); // non deve andare
    std::cout << "4" << std::endl;
    Guro.signForm(FormRobot); //non deve andare
    std::cout << "5" << std::endl;
    Guro.executeForm(FormRobot); // non deve andare
    std::cout << "6" << std::endl;
    Buro.signForm(ShrubbForm); //deve andare
    std::cout << "7" << std::endl;
    Buro.executeForm(ShrubbForm); //deve andare
    std::cout << "8" << std::endl;
    Buro.signForm(FormRobot); //deve andare
    std::cout << "9" << std::endl;
    Buro.executeForm(FormRobot); //deve andare
}
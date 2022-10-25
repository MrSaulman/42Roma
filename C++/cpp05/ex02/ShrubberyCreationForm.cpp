#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137), _target("")
{
    std::cout << "Costructor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Costructor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Destructor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj)
{
    std::cout << "Costructor Copy ShrubberyCreationForm" << std::endl;
    *this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
    std::cout << "Assignation ShrubberyCreationForm" << std::endl;
    if (this != &obj)
        this->_target = obj._target;
    return (*this);
}

bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const
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
        std::string ascii = "___________________§§_________________________\n"
                            "_____________§____§§§§________________________\n"
                            "__§___§__________§§§§§§_________________§_____\n"
                            "_________§§_____§§§§§§§§______________________\n"
                            "_______________§§§§§§§§§§______§______________\n"
                            "§___§_________§§§§§§§§§§§§_________§__________\n"
                            "_________________§§§§§§_______________________\n"
                            "__________§_____§§§§§§§§______________________\n"
                            "_______________§§§§§§§§§§_____§_______________\n"
                            "______________§§§§§§§§§§§§____________________\n"
                            "_§_____§_____§§§§§§§§§§§§§§§__________________\n"
                            "___________§§§§§§§§§§§§§§§§§§§______§____§____\n"
                            "________§§§§§§§§§§§§§§§§§§§§§§§§______________\n"
                            "__§___________§§§§§§§§§§§§____________________\n"
                            "____________§§§§§§§§§§§§§§§§_____§____________\n"
                            "_________§§§§§§§§§§§§§§§§§§§§§§_________§_____\n"
                            "______§§§§§§§§§§§§§§§§§§§§§§§§§§§_____________\n"
                            "___§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§______§___\n"
                            "__§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§_______\n"
                            "§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§_____\n"
                            "________________§§§§§§§§______________________\n"
                            "___§______§_____§§§§§§§§______________________\n"
                            "________________§§§§§§§§____§_________§_______\n";
        std::string fileName = (this->_target + "_shrubbery");
        std::ofstream file;
        file.open(fileName.c_str());
        file << ascii;
        file.close();
        std::cout << "File is created" << std::endl;
		return true;
    }
}

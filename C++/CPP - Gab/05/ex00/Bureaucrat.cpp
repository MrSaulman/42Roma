#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Constructor Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    std::cout << "Constructor Bureaucrat" << std::endl;
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name)
{
    setGrade(obj._grade);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor Bureaucrat" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
    (void)obj;
    return *this;
}

void Bureaucrat::incrementGrade()
{
    int grado = _grade - 1;
    setGrade(grado);
}
void Bureaucrat::decrementGrade()
{
    int grado = _grade + 1;
    setGrade(grado);
}

std::string const& Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
    {
        this->_grade = 1;
        throw GradeTooLowException();
    }
    else if (grade > 150)
    {
        this->_grade = 150;
        throw GradeTooHighException();
    }
    else
        this->_grade = grade;  
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Errore GradeTooHighException: grade is too high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Errore GradeTooLowException: grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << "<" << obj.getName() << "> ,bureaucrat grade <" << obj.getGrade() << ">" << std::endl;
    return out;
}

#include "Form.hpp"

Form::Form() : _name(""), _grade_sign(1), _grade_execute(1)
{
    std::cout << "Constructor Form" << std::endl;
}

Form::Form(std::string const name, int grade_sign, int grade_execute) : _name(name), _sign(false), _grade_sign(grade_sign), _grade_execute(grade_execute) 
{
    std::cout << "Constructor Form" << std::endl;
}

Form::Form(const Form &obj) : _name(obj._name), _sign(obj._sign), _grade_sign(obj._grade_sign), _grade_execute(obj._grade_execute)
{
    std::cout << "Copy Constructor Form" << std::endl;
}

Form::~Form()
{
    std::cout << "Destructor Form" << std::endl;
}

Form& Form::operator=(const Form &obj)
{
    (void)obj;
    return *this;
}

std::string Form::getName() const
{
    return (this->_name);
}

bool Form::getSign()
{
    return (this->_sign);
}

int Form::getGradeSign() const
{
    return (this->_grade_sign);
}

int Form::getGradeExecute() const
{
    return (this->_grade_execute);
}

Form::GradeTooHighException::GradeTooHighException() {}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Errore GradeTooHighException: grade is too high";
}

Form::GradeTooLowException::GradeTooLowException() {}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Errore GradeTooLowException: grade is too low";
}

void Form::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() < this->_grade_sign)
        this->_sign = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << "<" << obj.getName() << "> ,Form grade to sign <" << obj.getGradeSign() << ">" << " , form grade to exec <" << obj.getGradeExecute() << ">" << std::endl;
    return out;
}

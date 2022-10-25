#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <exception>
#include "Form.hpp"

class Form;
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _name;
        bool _sign;
        const int _grade_sign;
        const int _grade_execute;
    public:
        Form();
        Form(std::string const name, int grade_sign, int grade_execute);
        Form(const Form &obj);
        virtual ~Form();
        Form& operator=(const Form &obj);
        virtual bool execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                GradeTooHighException();
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException();
                const char* what() const throw();
        };
        class NotSignedException : public std::exception
		{
			public:
                NotSignedException();
				const char *what() const throw();
		};
        std::string getName() const;
        bool getSign() const;
        int getGradeSign() const;
        int getGradeExecute() const;
        void beSigned(const Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif
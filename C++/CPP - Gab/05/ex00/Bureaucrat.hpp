#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat &obj);

        void setGrade(int grade);
        void incrementGrade();
        void decrementGrade();

        std::string const& getName() const;
        int getGrade() const;

    class GradeTooHighException: public std::exception {
        public:
            GradeTooHighException();
            const char* what() const throw();
    };

    class GradeTooLowException: public std::exception {
        public:
            GradeTooLowException();
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
#ifndef INTERN_HPP
#define INTERN_HPP
#include "Form.hpp"
#include <iostream>
class Form ;

class Intern {
    public:
        Intern();
        Intern(const Intern &obj);
        ~Intern(void);
        Intern &operator=(Intern const &obj);
        Form* makeForm(std::string formName, std::string target) const;
};

#endif
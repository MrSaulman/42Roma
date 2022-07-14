#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack(void){};
        ~MutantStack(void){};
        MutantStack(const MutantStack &obj)
        {
            *this = obj;
        }

        MutantStack &operator=(const MutantStack &obj)
        {
            if (this != &obj)
                *this = obj;
            return (*this);
        }

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin(void)
        {
            return (this->c.begin());
        }

        iterator end(void)
        {
            return (this->c.end());
        }
};

#endif
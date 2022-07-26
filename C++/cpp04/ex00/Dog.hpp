#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
    public:
        Dog();
        ~Dog();
        Dog(std::string _type);
        Dog(const Dog &obj);
        Dog& operator=(const Dog &obj);
        void makeSound(void) const;
};

#endif
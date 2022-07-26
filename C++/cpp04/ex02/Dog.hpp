#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal{
    private:
        Brain* brain;
    public:
        Dog();
        virtual ~Dog();
        Dog(std::string _type);
        Dog(const Dog &obj);
        Dog& operator=(const Dog &obj);
        void makeSound(void) const;
};

#endif
#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Constructor Dog" << std::endl; 
}

Dog::~Dog(){ std::cout << "Destructor Dog" << std::endl; }

Dog::Dog(std::string _type) { type = _type; }

Dog::Dog(const Dog &obj)
{
    *this = obj;
}

Dog& Dog::operator=(const Dog &obj)
{
    if (this != &obj)
        type = obj.type;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Sono un cane" << std::endl;
}

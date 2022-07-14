#include "Animal.hpp"

Animal::Animal(){ std::cout << "Constructor Animal" << std::endl; }
Animal::~Animal(){ std::cout << "Destructor Animal" << std::endl; }
Animal::Animal(const Animal &obj) : type(obj.type) {}

Animal& Animal::operator=(const Animal &obj)
{
    std::cout << "Operator overload" << std::endl;
    if (this != &obj)
        type = obj.type;
    return *this;
}

std::string Animal::getType(void) const
{
    return this->type;
}

void Animal::setType(std::string _type)
{
    type = _type;
}

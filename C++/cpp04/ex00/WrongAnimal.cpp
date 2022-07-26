#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){ std::cout << "Constructor WrongAnimal" << std::endl; }
WrongAnimal::~WrongAnimal(){ std::cout << "Destructor WrongAnimal" << std::endl; }
WrongAnimal::WrongAnimal(const WrongAnimal &obj) : type(obj.type) {}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
    if (this != &obj)
        type = obj.type;
    return *this;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Sono un WrongAnimale" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return this->type;
}

void WrongAnimal::setType(std::string _type)
{
    type = _type;
}

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "Constructor WrongCat" << std::endl; 
}

WrongCat::~WrongCat(){ std::cout << "Destructor WrongCat" << std::endl; }

WrongCat::WrongCat(std::string _type){ type = _type; }

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
    if (this != &obj)
        type = obj.type;
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "Sono un WrongCat" << std::endl;
}

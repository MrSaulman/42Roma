#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Constructor Cat" << std::endl;
}

Cat::~Cat(){ std::cout << "Destructor Cat" << std::endl; delete this->brain; }

Cat::Cat(std::string _type) { type = _type; }

Cat::Cat(const Cat &obj)
{
    *this = obj;
}

Cat& Cat::operator=(const Cat &obj)
{
    if (this != &obj)
        type = obj.type;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Sono un gatto" << std::endl;
}

# include "Zombie.hpp"
# include <iostream>

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout << this->name << ": has been destoyed" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
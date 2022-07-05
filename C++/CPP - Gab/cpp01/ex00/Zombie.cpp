# include "Zombie.hpp"
# include <string>
# include <iostream>

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout << this->name << ": has been destroyed" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}



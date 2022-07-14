#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string name): _name(name)
{
    _name = name;
}

Zombie::~Zombie(void)
{
    std::cout << _name << "has been destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

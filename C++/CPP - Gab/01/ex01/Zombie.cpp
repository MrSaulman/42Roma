#include "Zombie.hpp"

Zombie::Zombie(void)
{
    
}

Zombie::~Zombie(void)
{
    std::cout << _name << "has been destroyed" << std:: endl;
}

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie* newZombie( std::string name )
{
    Zombie *nuovo;

    nuovo = new Zombie(name);
    return (nuovo);
}

void Zombie::announce(void)
{
    std::cout << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void randomChump(std::string name)
{
    Zombie nuovo(name);
    nuovo.announce();
}

void Zombie::setName(std::string name)
{
    _name = name;
}

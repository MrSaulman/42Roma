#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
   Zombie *nuovo;

    nuovo = new Zombie(name);
    return (nuovo);
}

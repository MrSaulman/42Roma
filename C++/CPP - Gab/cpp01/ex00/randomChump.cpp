# include "Zombie.hpp"
# include <iostream>

void randomChump(std::string name)
{
    Zombie r_zombie(name);
    r_zombie.announce();
}


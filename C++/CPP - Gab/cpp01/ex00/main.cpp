#include "Zombie.hpp"

int main()
{
    Zombie *zombie_pazzo;

    zombie_pazzo = newZombie("zombie_pazzo1");
    zombie_pazzo->announce();
    randomChump("ziobulubu");
    zombie_pazzo->~Zombie();
    return (0);
}
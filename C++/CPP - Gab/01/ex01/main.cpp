#include "Zombie.hpp"
#include <iostream>
int main()
{
    Zombie *horde;
    horde = zombieHorde(10, "orda");
    for (int i = 0; i < 10; i++)
    {
        horde[i].announce();
    }
    delete []horde;
    return (0);
}
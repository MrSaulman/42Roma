#include "Zombie.hpp"

int main()
{
    Zombie *horde;
    int n = 7;

    horde = zombieHorde(n, "hooooorde_soldier");
    for(int i = 0; i < n; i++)
        horde[i].announce();
    delete[] horde;
    return (0);
}
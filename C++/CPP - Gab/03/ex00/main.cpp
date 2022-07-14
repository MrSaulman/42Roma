#include "ClapTrap.hpp"

int main()
{
    ClapTrap lollo("lollo");
    ClapTrap franco("franco");
    ClapTrap gigi("gigi");

    lollo.attack("franco");
    franco.takeDamage(10);
    gigi.attack("franco");
    franco.takeDamage(10);
    franco.beRepaired(100);
}
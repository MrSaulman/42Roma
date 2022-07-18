#include "ClapTrap.hpp"

int main()
{
    ClapTrap lollo("lollo");
    ClapTrap franco("franco");
    ClapTrap gigi("gigi");

    lollo.attack("franco");
    franco.takeDamage(0);
    gigi.attack("franco");
    franco.takeDamage(0);
    franco.beRepaired(69);
}
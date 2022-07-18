#include "ScavTrap.hpp"

int main()
{
    ScavTrap lollo("lollo");
    ScavTrap franco("franco");
    ScavTrap gigi("gigi");

    lollo.attack("franco");
    franco.takeDamage(20);
    gigi.attack("franco");
    franco.takeDamage(20);
    franco.beRepaired(20);
    franco.guardGate();
}

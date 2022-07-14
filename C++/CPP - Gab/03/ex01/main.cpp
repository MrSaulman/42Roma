#include "ScavTrap.hpp"

int main()
{
    ScavTrap lollo("lollo");
    ScavTrap franco("franco");
    ScavTrap gigi("gigi");

    lollo.attack("franco");
    franco.takeDamage(100);
    gigi.attack("franco");
    franco.takeDamage(100);
    franco.beRepaired(100);
    franco.guardGate();
}

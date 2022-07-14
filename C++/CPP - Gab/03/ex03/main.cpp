#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap lollo("lollo");
    DiamondTrap franco("franco");
    DiamondTrap gigi("gigi");

    franco.highFivesGuys();
    lollo.attack("franco");
    franco.takeDamage(100);
    gigi.attack("franco");
    franco.takeDamage(100);
    franco.beRepaired(100);
    
}

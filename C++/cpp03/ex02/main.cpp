#include "FragTrap.hpp"

int main()
{
    FragTrap lollo("lollo");
    FragTrap franco("franco");
    FragTrap gigi("gigi");

    franco.highFivesGuys();
    lollo.attack("franco");
    franco.takeDamage(30);
    gigi.attack("franco");
    franco.takeDamage(30);
    franco.beRepaired(30);
}

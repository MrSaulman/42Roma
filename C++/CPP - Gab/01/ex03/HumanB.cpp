#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{

}
HumanB::~HumanB(void)
{

}

void HumanB::attack(void)
{
    std::cout << _name << "attacks with is" << _weapon << std::endl;
}
void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}
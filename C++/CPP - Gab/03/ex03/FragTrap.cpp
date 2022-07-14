#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_hitpoints = 100;
    this->_energy_point = 100;
    this->_attack_manage = 30;
    std::cout << "Name FragTrap : " << "unknown" << " hitpoint: " << this->_hitpoints << " point: " << this->_energy_point << " attack manage: " << this->_attack_manage << std::endl;
}

FragTrap::~FragTrap()
{
    if (this->_name != "")
        std::cout << "Destructor FragTrap called for " << this->_name << std::endl;
    else
        std::cout << "Destructor FragTrap called for <unknown>" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitpoints = 100;
    this->_energy_point = 100;
    this->_attack_manage = 30;
    std::cout << "Name FragTrap: " << this->_name << " hitpoint: " << this->_hitpoints << " point: "  << this->_energy_point << " attack manage: " << this->_attack_manage << std::endl;
}

FragTrap::FragTrap(FragTrap const &obj) : ClapTrap(obj._name)
{
    *this = obj;
}

FragTrap &FragTrap::operator=(FragTrap const &obj)
{
    if (this == &obj)
        return (*this);
    this->_name = obj._name;
    this->_hitpoints = obj._hitpoints;
    this->_energy_point = obj._energy_point;
    this->_attack_manage = obj._attack_manage;
    return (*this);
}

void FragTrap::highFivesGuys()
{
    std::cout << "Give me 5!" << std::endl;
}

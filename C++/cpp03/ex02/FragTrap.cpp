#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_hitpoints = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "Name FragTrap : " << "unknown" << " hitpoint: " << this->_hitpoints << " point: " << this->_energy_points << " attack damage: " << this->_attack_damage << std::endl;
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
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "Name FragTrap: " << this->_name << " hitpoint: " << this->_hitpoints << " point: "  << this->_energy_points << " attack damage: " << this->_attack_damage << std::endl;
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
    this->_energy_points = obj._energy_points;
    this->_attack_damage = obj._attack_damage;
    return (*this);
}

void FragTrap::highFivesGuys()
{
    std::cout << "Give me 5!" << std::endl;
}

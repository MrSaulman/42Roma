#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hitpoints = 100;
    this->_energy_point = 50;
    this->_attack_manage = 20;
    std::cout << "Name ScavTrap : " << "unknown" << " hitpoint: " << this->_hitpoints << " point: " << this->_energy_point << " attack manage: " << this->_attack_manage << std::endl;
}

ScavTrap::~ScavTrap()
{
    if (this->_name != "")
        std::cout << "Destructor ScavTrap called for " << this->_name << std::endl;
    else
        std::cout << "Destructor ScavTrap called for <unknown>" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitpoints = 100;
    this->_energy_point = 50;
    this->_attack_manage = 20;
    std::cout << "Name ScavTrap: " << this->_name << " hitpoint: " << this->_hitpoints << " point: "  << this->_energy_point << " attack manage: " << this->_attack_manage << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &obj) : ClapTrap(obj._name)
{
    *this = obj;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &obj)
{
    if (this == &obj)
        return (*this);
    this->_name = obj._name;
    this->_hitpoints = obj._hitpoints;
    this->_energy_point = obj._energy_point;
    this->_attack_manage = obj._attack_manage;
    return (*this);
}

void ScavTrap::attack(std::string const & target)
{
    std::cout << "ScavTrap " << this->_name << " attack " << target << " ,causing " << this->_hitpoints << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->_name  << " have enterred in Gate keeper mode." << std::endl;
}

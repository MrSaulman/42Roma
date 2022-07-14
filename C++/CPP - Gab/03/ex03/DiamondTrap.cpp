#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    this->_hitpoints = 100;
    this->_energy_point = 50;
    this->_attack_manage = 30;
    std::cout << "Name DiamondTrap : " << "unknown" << " hitpoint: " << this->_hitpoints << " point: " << this->_energy_point << " attack manage: " << this->_attack_manage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    if (this->name != "")
        std::cout << "Destructor DiamondTrap called for " << this->name << std::endl;
    else
        std::cout << "Destructor DiamondTrap called for <unknown>" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name_) : ClapTrap(name_), ScavTrap(name_), FragTrap(name_)
{
    this->_hitpoints = 100;
    this->_energy_point = 50;
    this->_attack_manage = 30;
    this->name = name_;
    this->ClapTrap::_name = name_ + "_clap_name";
    std::cout << "Name DiamondTrap: " << this->name << " hitpoint: " << this->_hitpoints << " point: "  << this->_energy_point << " attack manage: " << this->_attack_manage << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &obj) : ClapTrap(obj._name + "_clap_name")
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    *this = obj;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &obj)
{
    if (this == &obj)
        return (*this);
    this->name = obj.name;
    this->_hitpoints = obj._hitpoints;
    this->_energy_point = obj._energy_point;
    this->_attack_manage = obj._attack_manage;
    return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "Clapname " << this->ClapTrap::_name << ", Diamondname " << this->name << std::endl;
}

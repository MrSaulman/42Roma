#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    this->_hitpoints = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
    std::cout << "Name DiamondTrap : " << "unknown" << " hitpoint: " << this->_hitpoints << " point: " << this->_energy_points << " attack damage: " << this->_attack_damage << std::endl;
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
    this->_energy_points = 50;
    this->_attack_damage = 30;
    this->name = name_;
    this->ClapTrap::_name = name_ + "_clap_name";
    std::cout << "Name DiamondTrap: " << this->name << " hitpoint: " << this->_hitpoints << " point: "  << this->_energy_points << " attack damage: " << this->_attack_damage << std::endl;
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
    this->_energy_points = obj._energy_points;
    this->_attack_damage = obj._attack_damage;
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

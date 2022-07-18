#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hitpoints = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "Name ScavTrap: unknown, hitpoints: " << this->_hitpoints << ", energy points: " << this->_energy_points << ", attack damage: " << this->_attack_damage << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitpoints = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "Name ScavTrap: " << this->_name << ", hitpoints: " << this->_hitpoints << ", energy points: " << this->_energy_points << ", attack damage: " << this->_attack_damage << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &obj) : ClapTrap(obj._name)
{
    *this = obj;
}

ScavTrap::~ScavTrap()
{
    if (this->_name != "")
        std::cout << "Destructor ScavTrap called for " << this->_name << std::endl;
    else
        std::cout << "Destructor ScavTrap called for <unknown>" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &obj)
{
    if (this == &obj)
        return (*this);
    this->_name = obj._name;
    this->_hitpoints = obj._hitpoints;
    this->_energy_points = obj._energy_points;
    this->_attack_damage = obj._attack_damage;
    return (*this);
}

void ScavTrap::attack(std::string const & target)
{
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->_name  << " has entered in Gate keeper mode." << std::endl;
}

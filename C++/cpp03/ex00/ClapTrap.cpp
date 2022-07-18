#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitpoints(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "Name: unknown, hitpoints: " << this->_hitpoints
              << " energy points: " << this->_energy_points << " attack damage: " << this->_attack_damage << std::endl;
}

ClapTrap::~ClapTrap()
{
    if (this->_name != "")
        std::cout << "Destructor called for " << this->_name << std::endl;
    else
        std::cout << "Destructor called for <unknown>" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "Name: " << this->_name << ", hitpoints: " << this->_hitpoints << ", energy points: " << this->_energy_points << ", attack damage: " << this->_attack_damage << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &obj)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this == &obj)
        return (*this);
    this->_name = obj._name;
    this->_hitpoints = obj._hitpoints;
    this->_energy_points = obj._energy_points;
    this->_attack_damage = obj._attack_damage;
    return (*this);
}

void ClapTrap::attack(std::string const &target)
{
    if (this->_energy_points > 0 && this->_hitpoints > 0)
    {
        std::cout << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_points -= 1;
    }
    else
        std::cout << this->_name << "cannot attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitpoints <= 0)
    {
        std::cout << "Name: " << this->_name << " is already dead" << std::endl;
        return;
    }
    std::cout << this->_name << " has taken damage for " << amount << " hitpoints." << std::endl;
    this->_hitpoints -= amount;
    std::cout << "Name: " << this->_name << ", hitpoints: " << this->_hitpoints << ", energy points: " << this->_energy_points << ", attack damage: " << this->_attack_damage << std::endl;
    if (_hitpoints <= 0)
        std::cout << "Name: " << this->_name << " died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitpoints <= 0)
    {
        std::cout << "Name: " << this->_name << " can't be repaired because it's dead." << std::endl;
        return;
    }
    else if (_energy_points <= 0)
    {
        std::cout << "Name: " << this->_name << " can't be repaired because it's out of energy points." << std::endl;
        return;
    }
    std::cout << this->_name << " has been repaired for " << amount << " hitpoints." << std::endl;
    this->_hitpoints += amount;
    this->_energy_points--;
    std::cout << "Name: " << this->_name << ", hitpoints: " << this->_hitpoints << ", energy points: " << this->_energy_points << ", attack damage: " << this->_attack_damage << std::endl;
}

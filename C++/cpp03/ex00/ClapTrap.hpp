#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <string>


class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitpoints;
        unsigned int _energy_points;
        unsigned int _attack_damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(ClapTrap const &obj);
        ClapTrap &operator=(ClapTrap const &obj);
        
        void attack(std::string const & target);
        void beRepaired(unsigned int amount);
        void takeDamage(unsigned int amount);
};

#endif

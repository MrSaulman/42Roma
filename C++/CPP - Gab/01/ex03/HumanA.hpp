#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA{
    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA(void);
        void attack(void);
    private:
        std::string _name;
        Weapon &_weapon;
};

#endif
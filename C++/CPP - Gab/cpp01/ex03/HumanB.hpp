#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"
# include <string>

class HumanB
{
    public:
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        void attack();

    private:
        Weapon *weapon;
        std::string name;
};

#endif
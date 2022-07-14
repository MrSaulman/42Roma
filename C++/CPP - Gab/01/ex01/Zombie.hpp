#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
public:
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);
    Zombie* newZombie( std::string name );
    Zombie* zombieHorde( int N, std::string name );
    
    void setName(std::string name);
    void    announce(void);
    void randomChump( std::string name );
private:

    std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
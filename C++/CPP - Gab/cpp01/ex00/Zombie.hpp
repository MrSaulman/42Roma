#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        Zombie(std::string name);
        void announce(void);

    private:
        std::string name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
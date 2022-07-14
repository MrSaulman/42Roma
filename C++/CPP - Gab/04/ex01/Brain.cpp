#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor" << std::endl;
}

Brain::Brain(const Brain &obj)
{
    *this = obj;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor" << std::endl;
}

Brain& Brain::operator=(const Brain &obj)
{
    if (this != &obj)
    {
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = obj.ideas[i];
        }
    }
    return (*this);
}
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
    public:
        Brain();
        Brain(const Brain &obj);
        ~Brain();
        Brain& operator=(const Brain &obj);
        
        std::string ideas[100];
};

#endif
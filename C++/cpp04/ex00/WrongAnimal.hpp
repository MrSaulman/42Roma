#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal{
    protected:
        std::string type;
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &obj);
        WrongAnimal& operator=(const WrongAnimal &obj);
        void makeSound(void) const;
        std::string getType(void) const;
        void setType(std::string _type);
};

#endif
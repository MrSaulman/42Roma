#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal &obj);
        Animal& operator=(const Animal &obj);
        virtual void makeSound(void) const;
        std::string getType(void) const;
        void setType(std::string _type);
};





/*class WrongAnimal {
    protected:
        std::string _type;
    public:
        void makeSound(void);
};

class WrongCat : public WrongAnimal{
    public:
        void makeSound(void);
};*/

#endif
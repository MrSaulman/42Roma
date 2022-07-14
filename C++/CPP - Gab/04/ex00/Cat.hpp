#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
    public:
        Cat();
        ~Cat();
        Cat(std::string _type);
        Cat(const Cat &obj);
        Cat& operator=(const Cat &obj);
        void makeSound(void) const;
};

#endif
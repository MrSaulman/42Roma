#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(std::string type);
        WrongCat& operator=(const WrongCat &obj);
        void makeSound() const;
};

#endif
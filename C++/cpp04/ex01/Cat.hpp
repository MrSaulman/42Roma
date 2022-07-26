#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal{
    private:
        Brain* brain;
    public:
        Cat();
        virtual ~Cat();
        Cat(std::string _type);
        Cat(const Cat &obj);
        Cat& operator=(const Cat &obj);
        void makeSound(void) const;
};

#endif
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
bool easyfind(T& container, int occurrence)
{
    try{
        typename T::iterator i;
        i = std::find(container.begin(), container.end(), occurrence);
        if (i == container.end())
            throw std::runtime_error("Not found");
        return (true);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
        return (false);
    }
}

#endif
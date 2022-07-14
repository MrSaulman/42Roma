#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <class T>
void func(T value)
{
    std::cout << "Value: " << value << std::endl;
}

template<class T>
void iter(T *a, int b, void (*f)(T const &))
{
    for (int i = 0; i < b; i++)
    {
        f(a[i]);
    }
}

#endif

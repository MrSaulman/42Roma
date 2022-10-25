#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template<class T>
void swap(T &a, T&b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

template<class T>
const T& min(T& a, T& b)
{
    if (a == b)
        return (b);
    return ((a < b) ? a : b);
}

template<class T>
const T& max(T& a, T& b)
{
    if (a == b)
        return (b);
    return ((a > b) ? a : b);
}

#endif
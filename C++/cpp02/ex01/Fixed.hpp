#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
    int _value;
    static const int _fractional = 8;
public:
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed &obj);
    Fixed& operator=(const Fixed &obj);
    ~Fixed();
    int toInt(void) const;
    float toFloat(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif

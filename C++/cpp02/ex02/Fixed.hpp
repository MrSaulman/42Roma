#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
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
    ~Fixed();

    Fixed& operator=(const Fixed &obj);
    bool operator>(const Fixed &obj) const;
    bool operator>=(const Fixed &obj) const;
    bool operator<(const Fixed &obj) const;
    bool operator<=(const Fixed &obj) const;
    bool operator==(const Fixed &obj) const;
    bool operator!=(const Fixed &obj) const;

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

    static Fixed& min(Fixed& a, Fixed& b);
    static Fixed const& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static Fixed const& max(const Fixed& a, const Fixed& b);
    
    int toInt(void) const;
    float toFloat(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

const Fixed operator+(const Fixed& a, const Fixed& b);
const Fixed operator-(const Fixed& a, const Fixed& b);
const Fixed operator*(const Fixed& a, const Fixed& b);
const Fixed operator/(const Fixed& a, const Fixed& b);
std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif

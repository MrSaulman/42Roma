#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
}

Fixed::Fixed(const int n)
{
    _value = (int)n * (1 << _fractional);
}

Fixed::Fixed(const float n)
{
    _value = (int)roundf(n * (1 << _fractional));
}

Fixed::Fixed(const Fixed &obj)
{
    *this = obj;
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed &obj)
{
    _value = obj._value;
    return *this;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

int Fixed::toInt(void) const
{
    return ((int)this->_value / (1 << _fractional));
}

float Fixed::toFloat(void) const
{
    return ((float)this->_value / (1 << _fractional));
}

bool Fixed::operator>(const Fixed& obj) const { return (_value > obj._value); }
bool Fixed::operator>=(const Fixed& obj) const { return (_value >= obj._value); }
bool Fixed::operator<(const Fixed& obj) const { return (_value < obj._value); }
bool Fixed::operator<=(const Fixed& obj) const { return (_value <= obj._value); }
bool Fixed::operator==(const Fixed& obj) const { return (_value == obj._value); }
bool Fixed::operator!=(const Fixed& obj) const { return (_value != obj._value); }

const Fixed operator+(const Fixed& a, const Fixed& b){ return (a.toFloat() + b.toFloat()); }
const Fixed operator-(const Fixed& a, const Fixed& b){ return (a.toFloat() - b.toFloat()); }
const Fixed operator*(const Fixed& a, const Fixed& b){ return (a.toFloat() * b.toFloat()); }
const Fixed operator/(const Fixed& a, const Fixed& b){ return (a.toFloat() / b.toFloat()); }

Fixed& Fixed::operator++()
{
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed c = *this;
    _value++;
    return (c);
}

Fixed& Fixed::operator--()
{
    --_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed c = *this;
    _value--;
    return (c);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) { return a <= b ? a : b; }
Fixed const& Fixed::min(const Fixed& a, const Fixed& b) { return a <= b ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return a >= b ? a : b; }
Fixed const& Fixed::max(const Fixed& a, const Fixed& b) { return a >= b ? a : b; }


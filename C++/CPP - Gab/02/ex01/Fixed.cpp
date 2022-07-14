#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    _value = (int)n * (1 << _fractional);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
{
    _value = (int)roundf(n * (1 << _fractional));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
    std::cout << "Assignation operator called" << std::endl;
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
    std::cout << "getRawBits member function called" << std::endl;
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

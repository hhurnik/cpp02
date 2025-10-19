#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other; //or this->fixedPointValue = other.fixedPointValue;
}
//copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixedPointValue = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}


//new to this ex01
//int constructor
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    fixedPointValue = value << fractionalBits;
    //the same as value * 2^8
}

//float constructor
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(value * (1 << fractionalBits));
    //multiply by 256 and then round it 
}


//convert to float
float Fixed::toFloat(void) const
{
    return ((float)fixedPointValue / (1 << fractionalBits));
}

// Convert to int
int Fixed::toInt(void) const 
{
    return (fixedPointValue >> fractionalBits);
    //the same as dividing by 2^8
}

//overload of <<
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}


//ex02
//coparison operators
bool Fixed::operator>(const Fixed &other) const 
{
    return (fixedPointValue > other.fixedPointValue);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (fixedPointValue < other.fixedPointValue);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (fixedPointValue >= other.fixedPointValue);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (fixedPointValue <= other.fixedPointValue);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (fixedPointValue == other.fixedPointValue);
}

//I compare binary values, that's why fixedPointValue can be used
bool Fixed::operator!=(const Fixed &other) const
{
    return (fixedPointValue != other.fixedPointValue);
}

//arithmetic operators
//(+/-) could be fixedPointValue, but this could be used even with different scales
Fixed Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

//I work on floats first, but then constructor scales it to fixedPoint
Fixed Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

//to use fixedPointValue I'd need to scale - divide by the scale (or multiply in operator/)
Fixed Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    //division by zero allowed to crash
    return (Fixed(this->toFloat() / other.toFloat()));
}

//increment adn decrement
Fixed &Fixed::operator++()
{
    fixedPointValue++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    fixedPointValue++;
    return (temp);
}

Fixed &Fixed::operator--()
{
    fixedPointValue--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    fixedPointValue--;
    return (temp);
}

//min/max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}


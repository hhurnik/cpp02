#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int fixedPointValue;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &other); //copy constructor
    Fixed &operator=(const Fixed &other); //copy assignment operator overload
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
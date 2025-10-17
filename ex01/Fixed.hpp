#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int                 fixedPointValue;
        static const int    fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int value); // int constructor
        Fixed(const float value); //float constructor
        Fixed(const Fixed &other); //copy constructor
        Fixed &operator=(const Fixed &other); //copy assignment operator overload
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
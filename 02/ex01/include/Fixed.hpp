#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {

    public:
        Fixed(void);
        Fixed(const Fixed &src);
        Fixed(const int n);
        Fixed(const float n);
        ~Fixed(void);
        Fixed& operator=(const Fixed &rhs);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

std::ostream&   operator<<(std::ostream &o, Fixed const &fnbr);

#endif
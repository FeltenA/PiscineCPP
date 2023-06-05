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
    
        bool operator>(const Fixed &fnbr) const;
        bool operator<(const Fixed &fnbr) const;
        bool operator>=(const Fixed &fnbr) const;
        bool operator<=(const Fixed &fnbr) const;
        bool operator==(const Fixed &fnbr) const;
        bool operator!=(const Fixed &fnbr) const;
    
        Fixed operator+(const Fixed &fnbr);
        Fixed operator-(const Fixed &fnbr);
        Fixed operator*(const Fixed &fnbr);
        Fixed operator/(const Fixed &fnbr);

        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        static Fixed& min(Fixed& fnb1, Fixed& fnb2);
        static const Fixed& min(const Fixed& fnb1, const Fixed& fnb2);
        static Fixed& max(Fixed& fnb1, Fixed& fnb2);
        static const Fixed& max(const Fixed& fnb1, const Fixed& fnb2);

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

std::ostream&   operator<<(std::ostream &o, Fixed const &fnbr);

#endif
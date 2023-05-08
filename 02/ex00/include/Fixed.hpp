#ifndef FIXED_H
#define FIXED_H

class Fixed {

    public:
        Fixed(void);
        Fixed(const Fixed &src);
        ~Fixed(void);
        Fixed& operator=(const Fixed &src);

        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

#endif
#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {

    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point &src);
        ~Point(void);
        Point& operator=(const Point &rhs);

        Fixed getX(void) const;
        Fixed getY(void) const;
        void setX(const Fixed &x);
        void setY(const Fixed &y);

    private:
        Fixed const _x;
        Fixed const _y;
};

#endif
#include "Point.hpp"

Point::Point(void) : _x(0), _y(0){
    //std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {

}

Point::Point(const Point &src) {
    *this = src;
}

Point::~Point(void) {

}

Point& Point::operator=(const Point &rhs) {
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        (Fixed) this->_x = rhs.getX();
        (Fixed) this->_y = rhs.getY();
    }
    return (*this);
}

Fixed Point::getX(void) const {
    return (this->_x);
}

Fixed Point::getY(void) const {
    return (this->_y);
}

void Point::setX(const Fixed &x) {
    (Fixed) this->_x = x;
}

void Point::setY(const Fixed &y) {
    (Fixed) this->_y = y;
}
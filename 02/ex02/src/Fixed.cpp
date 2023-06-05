#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _fixedPointValue(roundf(n * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->setRawBits(rhs.getRawBits());
    return (*this);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const {
    return (this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream&   operator<<(std::ostream &o, Fixed const &fnbr) {
    o << fnbr.toFloat();
    return (o);
}

bool Fixed::operator>(const Fixed &fnbr) const {
    return (this->_fixedPointValue > fnbr.getRawBits());
}

bool Fixed::operator<(const Fixed &fnbr) const {
    return (this->_fixedPointValue < fnbr.getRawBits());
}

bool Fixed::operator>=(const Fixed &fnbr) const {
    return (this->_fixedPointValue >= fnbr.getRawBits());
}

bool Fixed::operator<=(const Fixed &fnbr) const {
    return (this->_fixedPointValue <= fnbr.getRawBits());
}

bool Fixed::operator==(const Fixed &fnbr) const {
    return (this->_fixedPointValue == fnbr.getRawBits());
}

bool Fixed::operator!=(const Fixed &fnbr) const {
    return (this->_fixedPointValue != fnbr.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fnbr) {
    return (Fixed(this->toFloat() + fnbr.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fnbr) {
    return (Fixed(this->toFloat() - fnbr.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fnbr) {
    return (Fixed(this->toFloat() * fnbr.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fnbr) {
    return (Fixed(this->toFloat() / fnbr.toFloat()));
}

Fixed& Fixed::operator++(void) {
    this->_fixedPointValue++;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);

    this->_fixedPointValue++;
    return (tmp);
}

Fixed& Fixed::operator--(void) {
    this->_fixedPointValue--;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);

    this->_fixedPointValue--;
    return (tmp);
}

Fixed& Fixed::min(Fixed& fnb1, Fixed& fnb2) {
    if (fnb1 < fnb2)
        return (fnb1);
    return (fnb2);
}

const Fixed& Fixed::min(const Fixed& fnb1, const Fixed& fnb2) {
    if (fnb1 < fnb2)
        return (fnb1);
    return (fnb2);
}

Fixed& Fixed::max(Fixed& fnb1, Fixed& fnb2) {
    if (fnb1 > fnb2)
        return (fnb1);
    return (fnb2);
}

const Fixed& Fixed::max(const Fixed& fnb1, const Fixed& fnb2) {
    if (fnb1 > fnb2)
        return (fnb1);
    return (fnb2);
}
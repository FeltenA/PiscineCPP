#include "Data.hpp"

Data::Data(void) {

}

Data::Data(const Data& src) {
    (void)src;
}

Data::~Data(void) {

}

Data& Data::operator=(const Data& rhs) {
    (void)rhs;
    return (*this);
}
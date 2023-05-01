#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _index(0), _count(0) {
    std::cout << "PhoneBook contructor called" << std::endl;
}

PhoneBook::~PhoneBook(void) {
    std::cout << "PhoneBook destructor called" << std::endl;
}

void PhoneBook::add_contact(Contact contact) {
    this->_contacts[this->_index] = contact;
    this->_index++;
    if (this->_index > 7)
        this->_index = 0;
    if (this->_count < 8)
        this->_count++;
}

Contact PhoneBook::get_contact(int index) const {
    return (this->_contacts[index]);
}

int PhoneBook::get_count(void) const {
    return (this->_count);
}
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class   PhoneBook {

    private:
        Contact _contacts [8];
        int     _index;
        int     _count;

    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void add_contact(Contact contact);
        Contact get_contact(int index) const;
        int get_count(void) const;
};

#endif
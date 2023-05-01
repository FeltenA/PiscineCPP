#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

std::string get_value_string(std::string prompt)
{
    std::string str;

    while (!std::cin.eof())
    {
        std::cout << prompt << ": ";
        std::getline(std::cin, str);
        if (str != "" || std::cin.eof())
            break;
        std::cout << "Input cannot be empty" << std::endl;
    }
    if (std::cin.eof())
        return ("");
    return (str);
}

void    add_contact(PhoneBook *phonebook)
{
    Contact contact;

    contact.set_first_name(get_value_string("First name"));
    contact.set_last_name(get_value_string("Last name"));
    contact.set_nickname(get_value_string("Nickname"));
    contact.set_phone_number(get_value_string("Phone number"));
    contact.set_darkest_secret(get_value_string("Darkest secret"));
    if (contact.get_first_name() != "" && contact.get_last_name() != "" && contact.get_nickname() != "" && contact.get_phone_number() != "" && contact.get_darkest_secret() != "")
        phonebook->add_contact(contact);
}

std::string get_padded_string(std::string str)
{
    int len;

    len = str.length();
    if (len <= 10)
        return (str.insert(0, 10 - len, ' '));
    else
        return (str.substr(0, 9) + ".");
}

void    search_contact(PhoneBook *phonebook)
{
    int count;
    int index;

    count = phonebook->get_count();
    index = 0;
    if (count == 0)
    {
        std::cout << "No contacts in phonebook" << std::endl;
        return;
    }
    while (index < count)
    {
        std::cout << "         " << index << "|";
        std::cout << get_padded_string(phonebook->get_contact(index).get_first_name()) << "|";
        std::cout << get_padded_string(phonebook->get_contact(index).get_last_name()) << "|";
        std::cout << get_padded_string(phonebook->get_contact(index).get_nickname()) << std::endl;
        index++;
    }
    while (1)
    {
        std::string str = get_value_string("Enter index");
        if (std::cin.eof())
            return;
        std::istringstream(str) >> index;
        if (str.length() == 1 && std::isdigit(str[0]) && index >= 0 && index < count)
            break;
        std::cout << "Index not valid" << std::endl;
    }
    std::cout << "First name: " << phonebook->get_contact(index).get_first_name() << std::endl;
    std::cout << "Last name: " << phonebook->get_contact(index).get_last_name() << std::endl;
    std::cout << "Nickname: " << phonebook->get_contact(index).get_nickname() << std::endl;
    std::cout << "Phone number: " << phonebook->get_contact(index).get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << phonebook->get_contact(index).get_darkest_secret() << std::endl;
}

int main(void)
{
    PhoneBook phonebook;

    while (!std::cin.eof())
    {
        std::string str;
        std::cout << "Enter command: ";
        std::getline(std::cin, str);
        if (str == "ADD")
            add_contact(&phonebook);
        else if (str == "SEARCH")
            search_contact(&phonebook);
        else if (str == "EXIT")
            break;
    }
    return (0);
}
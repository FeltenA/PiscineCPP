#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {
    this->functs["DEBUG"] = &Harl::debug;
    this->functs["INFO"] = &Harl::info;
    this->functs["WARNING"] = &Harl::warning;
    this->functs["ERROR"] = &Harl::error;
}

Harl::~Harl(void) {
    return;
}

void    Harl::complain(std::string level) {
    std::map<std::string, void (Harl::*)(void)>::iterator iter;
    iter = this->functs.find(level);
    if (iter != this->functs.end())
        (this ->*iter->second)();
}

void    Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
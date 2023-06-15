#include "Serializer.hpp"
#include <iostream>

int main(void) {
    Data* ptr = new Data();
    uintptr_t raw = Serializer::serialize(ptr);
    Data* test = Serializer::deserialize(raw);
    if (ptr == test)
        std::cout << "ptr equals test" << std::endl;
    delete test;
    return (0);
}
#ifndef ITER_H
#define ITER_H

#include <iostream>

template<typename T>
void iter(T* array, int len, void (*f)(T&)) {
    for (int i = 0; i < len; i++)
        (*f)(array[i]);
}

template<typename T>
void print(T& i) {
    std::cout << i << std::endl;
}

#endif
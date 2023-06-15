#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

template<typename T>
int easyfind(T& container, int value) {
    if (std::find(container.begin(), container.end(), value) != container.end())
        return (std::distance(container.begin(), std::find(container.begin(), container.end(), value)));
    else
        return (-1);
}

#endif
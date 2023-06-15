#ifndef WHATEVER_H
#define WHATEVER_H

template <typename T>
void swap(T& a, T& b) {
    T save = a;
    a = b;
    b = save;
}

template <typename T>
T& min(T& a, T& b) {
    if (a > b)
        return (b);
    return (a);
}

template <typename T>
T& max(T& a, T& b) {
    if (a > b)
        return (a);
    return (b);
}

#endif
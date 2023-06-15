#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template<typename T>
class Array {
    public:
        Array(void) : _n(0) {
            this->_array = new T;
        }

        Array(unsigned int n) : _n(n) {
            this->_array = new T[n];
        }

        Array(const Array& src) : _n(src.size()) {
            unsigned int n = src.size();
            this->_array = new T[n];
            this->_n = n;
            for (unsigned int i = 0; i < n; i++)
                this->_array[i] = src[i];
        }

        ~Array(void) {
            if (!this->_n)
                delete this->_array;
            else
                delete[] this->_array;
        }

        Array& operator=(const Array& rhs) {
            if (this != &rhs) {
                unsigned int n = rhs.size();
                if (!this->_n)
                    delete this->_array;
                else
                    delete[] this->_array;
                this->_array = new T[n];
                this->_n = n;
                for (unsigned int i = 0; i < n; i++)
                    this->_array[i] = rhs[i];
            }
            return (*this);
        }

        T& operator[](unsigned int i) const {
            if (i >= this->_n)
                throw std::exception();
            return (this->_array[i]);
        }

        unsigned int size(void) const {
            return (this->_n);
        }

    private:
        T* _array;
        unsigned int _n;
};

#endif
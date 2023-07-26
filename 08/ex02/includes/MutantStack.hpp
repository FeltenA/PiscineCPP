#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack<T>(void) : std::stack<T>(){}
        MutantStack<T>(const MutantStack<T>& src) : std::stack<T>(){
            *this = src;
        }
        ~MutantStack<T>(void){}

        MutantStack<T>& operator=(const MutantStack<T>& rhs){
            if (this != &rhs)
                std::stack<T>::operator=(rhs);
            return (*this);
        }

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin(void){
            return (this->c.begin());
        }
        iterator end(void){
            return (this->c.end());
        }
};

#endif
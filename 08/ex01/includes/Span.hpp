#ifndef SPAN_H
#define SPAN_H

#include <vector>

class Span {
    public:
        Span(void);
        Span(const Span& src);
        Span(unsigned int N);
        ~Span(void);

        Span& operator=(const Span& rhs);

        unsigned int getN(void) const;
        const std::vector<int>& getList(void) const;

        void addNumber(int num);
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan(void);
        int longestSpan(void);

    private:
        std::vector<int> _list;
        const unsigned int _N;
};

#endif
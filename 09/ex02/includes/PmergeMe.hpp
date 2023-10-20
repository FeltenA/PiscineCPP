#ifndef PMERGEME_H
#define PMERGEME_H

#include <vector>
#include <list>

class PmergeMe {
    public:
        PmergeMe(void);
        PmergeMe(int argc, char *argv[]);
        PmergeMe(PmergeMe& src);
        ~PmergeMe(void);

        PmergeMe& operator=(PmergeMe& rhs);

        std::vector<int> getVector(void) const;
        std::list<int> getList(void) const;

        void sortVector(void);
        void sortList(void);

    private:
        std::vector<int> _vect;
        std::list<int> _lst;
};

#endif
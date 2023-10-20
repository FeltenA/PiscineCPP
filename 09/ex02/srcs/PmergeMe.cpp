#include "PmergeMe.hpp"
#include <cstdlib>
#include <exception>

PmergeMe::PmergeMe(void) {

};

PmergeMe::PmergeMe(int argc, char *argv[]) {
    int nbr;
    for (int i = 1; i < argc; i++) {
        nbr = std::atoi(argv[i]);
        if (nbr < 0)
            throw std::exception();
        this->_lst.push_back(nbr);
        this->_vect.push_back(nbr);
    }
}

PmergeMe::PmergeMe(PmergeMe& src) {
    *this = src;
}

PmergeMe::~PmergeMe(void) {

}

PmergeMe& PmergeMe::operator=(PmergeMe& rhs) {
    if (this != &rhs) {
        this->_lst = rhs.getList();
        this->_vect = rhs.getVector();
    }
    return (*this);
}

std::vector<int> PmergeMe::getVector(void) const {
    return (this->_vect);
}

std::list<int> PmergeMe::getList(void) const {
    return (this->_lst);
}

int getJacobsthal(int n) {
    if (n == 0)
        return (0);
    else if (n == 1)
        return (1);
    return (getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2));
}

void mergeVector(std::vector<std::pair<int, int> >& vect, std::vector<std::pair<int, int> > lower, std::vector<std::pair<int, int> > higher, int left, int right) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < left && j < right) {
        if (lower[i] <= higher[j]) {
            vect[k] = lower[i];
            i++;
        }
        else {
            vect[k] = higher[j];
            j++;
        }
        k++;
    }
    while (i < left) {
        vect[k] = lower[i];
        i++;
        k++;
    }
    while (j < right) {
        vect[k] = higher[j];
        j++;
        k++;
    }
}

void mergeSortVector(std::vector<std::pair<int, int> >& vect, int n) {
    int i;
    std::vector<std::pair<int, int> > lower(n / 2), higher(n - n / 2);
    int left, right;

    if (n < 2)
        return ;
    left = n / 2;
    right = n - left;
    for (i = 0; i < left; i++)
        lower[i] = vect[i];
    for (i = 0; i < right; i++)
        higher[i] = vect[i + left];
    mergeSortVector(lower, left);
    mergeSortVector(higher, right);
    mergeVector(vect, lower, higher, left, right);
}

void PmergeMe::sortVector(void) {
    int i;
    int size = this->_vect.size();
    std::vector<std::pair<int, int> > main;
    std::vector<int> sorted;
    int last = 0;
    if (size < 2)
        return ;
    for (i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            if (this->_vect[i] < this->_vect[i + 1])
                main.push_back(std::make_pair(this->_vect[i], this->_vect[i + 1]));
            else
                main.push_back(std::make_pair(this->_vect[i + 1], this->_vect[i]));
        }
        else
            last = 1;
    }

    mergeSortVector(main, main.size());

    size = main.size();
    for (i = 0; i < size; i++)
        sorted.push_back(main[i].first);
    sorted.push_back(main[size - 1].second);

    i = 3;
    int jacNbrPrev = 0;
    int jacNbr = 1;
    int n;
    int nbr;
    int sizeSorted;
    while (jacNbrPrev < size) {
        jacNbrPrev = jacNbr;
        jacNbr = getJacobsthal(i);
        for (int j = jacNbr; j > jacNbrPrev; j--) {
            n = size - j;
            if (n < 0)
                continue ;
            nbr = main[n].second;
            sizeSorted = sorted.size();
            while (++n < sizeSorted) {
                if (nbr < sorted[n]) {
                    sorted.insert(sorted.begin() + n, nbr);
                    break ;
                }
            }
            if (n == sizeSorted)
                sorted.push_back(nbr);
        }
        i++;
    }
    if (last) {
        n = -1;
        nbr = this->_vect[this->_vect.size() - 1];
        sizeSorted = sorted.size();
        while (++n < sizeSorted) {
            if (nbr < sorted[n]) {
                sorted.insert(sorted.begin() + n, nbr);
                break ;
            }
        }
        if (n == sizeSorted)
            sorted.push_back(nbr);
    }
    this->_vect = sorted;
}

void mergeList(std::list<std::pair<int, int> >& lst, std::list<std::pair<int, int> > lower, std::list<std::pair<int, int> > higher, int left, int right) {
    std::list<std::pair<int, int> >::iterator itl = lower.begin();
    std::list<std::pair<int, int> >::iterator ith = higher.begin();
    std::list<std::pair<int, int> >::iterator itlst = lst.begin();
    int i = 0;
    int j = 0;

    while (i < left && j < right) {
        if (*itl <= *ith) {
            *itlst = *itl;
            itl++;
            i++;
        }
        else {
            *itlst = *ith;
            ith++;
            j++;
        }
        itlst++;
    }
    while (i < left) {
        *itlst = *itl;
        itl++;
        itlst++;
        i++;
    }
    while (j < right) {
        *itlst = *ith;
        ith++;
        itlst++;
        j++;
    }
}

void mergeSortList(std::list<std::pair<int, int> >& lst, int n) {
    std::list<std::pair<int, int> >::iterator itlst = lst.begin();
    int i;
    std::list<std::pair<int, int> > lower, higher;
    int left, right;

    if (n < 2)
        return ;
    left = n / 2;
    right = n - left;
    for (i = 0; i < left; i++) {
        lower.push_back(*itlst);
        itlst++;
    }
    for (i = 0; i < right; i++) {
        higher.push_back(*itlst);
        itlst++;
    }
    mergeSortList(lower, left);
    mergeSortList(higher, right);
    mergeList(lst, lower, higher, left, right);
}

void PmergeMe::sortList(void) {
    std::list<int>::iterator itlst;
    std::list<int>::iterator itlstSave;
    int size = this->_lst.size();
    std::list<std::pair<int, int> > main;
    std::list<int> sorted;
    int last = 0;
    if (size < 2)
        return ;
    for (itlst = this->_lst.begin(); itlst != this->_lst.end();) {
        itlstSave = itlst;
        if (++itlstSave == this->_lst.end()) {
            last = 1;
            break ;
        }
        
        if (*itlst < *itlstSave)
            main.push_back(std::make_pair(*itlst, *itlstSave));
        else
            main.push_back(std::make_pair(*itlstSave, *itlst));
        itlst++;
        itlst++;
    }

    mergeSortList(main, main.size());

    std::list<std::pair<int, int> >::iterator itmain = main.begin();
    for (; itmain != main.end(); itmain++)
        sorted.push_back(itmain->first);
    sorted.push_back(main.back().second);

    std::list<int>::iterator itsorted;
    int i = 3;
    size = main.size();
    int jacNbrPrev = 0;
    int jacNbr = 1;
    int n;
    int nbr;
    while (jacNbrPrev < size) {
        jacNbrPrev = jacNbr;
        jacNbr = getJacobsthal(i);
        for (int j = jacNbr; j > jacNbrPrev; j--) {
            itmain = main.begin();
            itsorted = sorted.begin();
            n = size - j;
            if (n < 0)
                continue ;
            std::advance(itmain, n);
            std::advance(itsorted, n);
            nbr = itmain->second;
            while (itsorted != sorted.end()) {
                if (nbr < *itsorted) {
                    sorted.insert(itsorted, nbr);
                    break ;
                }
                itsorted++;
            }
            if (itsorted == sorted.end())
                sorted.push_back(nbr);
        }
        i++;
    }
    if (last) {
        itmain = main.begin();
        itsorted = sorted.begin();
        nbr = this->_lst.back();
        while (itsorted != sorted.end()) {
            if (nbr < *itsorted) {
                sorted.insert(itsorted, nbr);
                break ;
            }
            itsorted++;
        }
        if (itsorted == sorted.end())
            sorted.push_back(nbr);
    }
    this->_lst = sorted;
}
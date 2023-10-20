#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

void printVector(std::vector<int> vect) {
    int size = vect.size();
    int i = -1;
    while (++i < size) {
        std::cout << vect[i];
        if (i + 1 < size)
            std::cout << " ";
        if (i > 10) {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
}

void printList(std::list<int> lst) {
    std::list<int>::iterator it = lst.begin();
    int i = 0;
    while (it != lst.end()) {
        std::cout << *it;
        if (++it != lst.end())
            std::cout << " ";
        i++;
        if (i > 10) {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    try {
        int size;
        clock_t begin, end;
        double time;
        PmergeMe test(argc, argv);

        size = test.getVector().size();
        std::cout << "Before: ";
        printVector(test.getVector());
        begin = clock();
        test.sortVector();
        end = clock();
        std::cout << "After:  ";
        printVector(test.getVector());
        time = ((double) (end - begin) / CLOCKS_PER_SEC) * 1000000;
        std::cout << "Time to process a range of " << size << " elements with std::vector : " << time << " microseconds" << std::endl;

        begin = clock();
        test.sortList();
        end = clock();
        time = ((double) (end - begin) / CLOCKS_PER_SEC) * 1000000;
        std::cout << "Time to process a range of " << size << " elements with std::list : " << time << " microseconds" << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "Error" << std::endl;
    }
    return (0);
}
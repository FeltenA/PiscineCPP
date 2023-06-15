#include "easyfind.hpp"
#include <string>

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int>    vect(arr, arr + sizeof(arr) / sizeof(int));
    std::list<int>  list(arr, arr + sizeof(arr) / sizeof(int));

    std::cout << easyfind(vect, 3) << std::endl;
    std::cout << easyfind(list, 3) << std::endl;
    std::cout << easyfind(list, 11) << std::endl;

    return 0;
}
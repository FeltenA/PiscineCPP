#include "iter.hpp"
#include <string>

class Test {
    public:
        Test(void) : _n(57) {};
        int getN(void) const {
            return (this->_n);
        };

    private:
        int _n;
};

std::ostream& operator<<(std::ostream& os, Test& rhs) {
    os << rhs.getN();
    return (os);
}

int main(void) {
    int array[] = {5, 6, 17, -3, 89};
    Test array2[5];

    iter(array, 5, print);
    std::cout << "--------------------------" << std::endl;
    iter(array2, 5, print);

    return 0;
}
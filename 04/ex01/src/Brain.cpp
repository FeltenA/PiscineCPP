#include "Brain.hpp"

Brain::Brain(void) {
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = "...";
}

Brain::Brain(const Brain& src) {
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = src.getIdea(i);
}

Brain::~Brain(void) {

}

Brain& Brain::operator=(const Brain& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = rhs.getIdea(i);
    }
    return (*this);
}

std::string Brain::getIdea(int n) const {
    if (n >= 0 && n < 100)
        return (this->_ideas[n]);
    return (0);
}

void Brain::setIdea(std::string idea, int n) {
    if (n >= 0 && n < 100)
        this->_ideas[n] = idea;
}
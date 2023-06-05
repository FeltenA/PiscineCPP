#ifndef BRAIN_H
#define BRAIN_H

#include <string>

class Brain {

    public:
        Brain(void);
        Brain(const Brain& src);
        ~Brain(void);

        Brain& operator=(const Brain& rhs);

        std::string getIdea(int n) const;
        void setIdea(std::string idea, int n);


    private:
        std::string _ideas [100];
};

#endif
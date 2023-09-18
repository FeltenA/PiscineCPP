#ifndef RPN_H
#define RPN_H

#include <stack>
#include <string>

class RPN {
    public:
        RPN(void);
        RPN(RPN& src);
        ~RPN(void);

        RPN& operator=(RPN& rhs);

        std::stack<int>& getPile(void);
        void setPile(std::stack<int>& pile);

        int evaluateString(std::string str);

    private:
        std::stack<int> _pile;
};

#endif
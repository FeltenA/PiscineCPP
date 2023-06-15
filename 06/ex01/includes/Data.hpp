#ifndef DATA_H
#define DATA_H

class Data {
    public:
        Data(void);
        Data(const Data& src);
        ~Data(void);

        Data& operator=(const Data& rhs);
};

#endif
#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <map>
#include <string>

class BitcoinExchange {
    public:
        BitcoinExchange(void);
        BitcoinExchange(std::string file_name);
        BitcoinExchange(BitcoinExchange& src);

        BitcoinExchange& operator=(BitcoinExchange& rhs);

        std::map<std::string, float>& getPrices(void);
        void setPrices(std::map<std::string, float>& prices);

    private:
        std::map<std::string, float> _prices;
};

#endif
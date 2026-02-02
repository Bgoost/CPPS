#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <iosfwd>
#include <cstdlib>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& dataFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    void loadData(const std::string& filename);
    float getExchangeRate(const std::string& date) const;
    void calculatePrice(const std::string inputFileName);
    std::string closestDate(const std::string fileDate);

private:
    std::map<std::string, float> _db;
};

#endif

#ifndef BITCOINEXchANGE_HPP
#define BITCOINEXchANGE_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <map>
#include <sstream>

class BitcoinExchange
{
public:
    BitcoinExchange(std::string& dbFilename);
    ~BitcoinExchange();

    void    processInputFile() const;
    float   getExchangeRateForDate(const std::string& date, float& value) const;

private:
    std::string const               _filename;
    std::map<std::string, float>    _database;
    void    loadDatabase(const std::string& filename);
    void    checkInput(std::string file) const;
    bool    isValidDate(const std::string& date) const;
    bool    isValidValue(const std::string& value) const;

    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange &operator=(const BitcoinExchange & other);
};

#endif
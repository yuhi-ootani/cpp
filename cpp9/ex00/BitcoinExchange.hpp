
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange {
  private:
    std::map<std::string, double> _db;
    void validateLine(const std::string line, std::string *date, float *value);

  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    bool validateDate(const std::string &date) const;
    bool validateValue(const std::string &valueStr, double *Value) const;
    void execute(const char *filename);
    void printResult(const std::string date, const int &value) const;
    std::map<std::string, double>::const_iterator & findRate(const std::string date) const;
};

#endif
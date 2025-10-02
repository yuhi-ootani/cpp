
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::ios_base::failure("could not open csv file.");

    std::string line;

    if (!std::getline(file, line))
        throw std::runtime_error("data.csv is empty");

    if (line != "date,exchange_rate")
        throw std::runtime_error("bad header in data.csv");

    while (std::getline(file, line)) {
        if (line.empty())
            throw std::runtime_error("empty line");

        if (line.find_first_of(" \t") != std::string::npos)
            throw std::runtime_error("invalid whitespace in line: " + line);

        std::stringstream ss(line);
        std::string date;
        std::string rateStr;

        if (!std::getline(ss, date, ','))
            throw std::runtime_error("empty date");
        if (!std::getline(ss, rateStr))
            throw std::runtime_error("empty rate");

        if (!validateDate(date))
            throw std::runtime_error("invalid date" + date);

        double rate;
        if (!validateValue(rateStr, &rate))
            throw std::runtime_error("invalid rate" + rateStr);

        if (rate < 0.0)
            throw std::runtime_error(" not a positive number. " + rateStr);

        _db[date] = rate;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        this->_db = other._db;
    }
    return *this;
}

static int isLeapYear(int y) {
    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
        return 29;
    else
        return 28;
}

static int HowManyDays(int y, int m) {
    switch (m) {
    case 4:
    case 6:
    case 9:
    case 11:
        return 31;
    case 2:
        return isLeapYear(y);
    default:
        return 31;
    }
}

bool BitcoinExchange::validateValue(const std::string &valueStr, double *Value) const {
    double rate;
    std::stringstream ss(valueStr);
    if (!(ss >> rate))
        return false;
    char extra;
    if (ss >> extra)
        return false;
    *Value = rate;
    return true;
}

bool BitcoinExchange::validateDate(const std::string &date) const {

    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    int daysInMonth = HowManyDays(year, month);

    if (day < 1 || day > daysInMonth)
        return false;

    return true;
}

static std::string trim(const std::string &str) {
    std::string::size_type b = 0, e = str.size();
    while (b < e && !std::isspace(str[b]))
        ++b;
    while (e > b && !std::isspace(str[e - 1]))
        --e;
    return str.substr(b, e - b);
}

void BitcoinExchange::validateLine(const std::string line, std::string *date, float *value) {
    std::stringstream ss(line);
    std::string valueStr;

    if (line.empty())
        throw std::runtime_error("line is empty");

    if (line.find('|') == std::string::npos)
        throw std::runtime_error("bad input => " + line);

    if (!std::getline(ss, *date, '|') || !std::getline(ss, valueStr))
        throw std::runtime_error("fail to get date or value => " + line);

    *date = trim(*date);
    valueStr = trim(valueStr);

    if (!validateDate(*date))
        throw std::runtime_error("invalid date => " + *date);

    double doubleVal;
    if (!validateValue(valueStr, &doubleVal))
        throw std::runtime_error("invalid value => " + valueStr);

    if (doubleVal < 0.0)
        throw std::runtime_error("not a positive number.");

    if (doubleVal > 1000.0)
        throw std::runtime_error("too large a number.");

    *value = static_cast<float>(doubleVal);
    return;
}

void printResult(const std::string date, const int &value)  
{
    if()
}

void BitcoinExchange::execute(const char *filename) {
    std::ifstream file(filname);
    if (!file.is_open())
        throw std::ios_base::failure("could not open file.");

    std::string line;

    if (!std::getline(file, line))
        throw std::runtime_error("file is empty.");

    if (line != "data | value")
        throw std::runtime_error("bad header in file");

    while (getline(file, line)) {

        std::string date;
        float value;

        try {
            validateLine(line, &date, &value);
            printResult(date, value);
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            continue;
        }
    }
}


#include "ScalarConverter.hpp"

void convert_from_char(const std::string &base) {
    char c = base[1];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    print_result(c, i, f, d);
}

static int parse_int(const std::string &base) {
    char *end;
    errno = 0;
    long result = std::strtol(base.c_str(), &end, 10);
    if (errno != 0 || *end != '\0' || result > std::numeric_limits<int>::max() ||
        result < std::numeric_limits<int>::min())
        throw std::invalid_argument("invalid integer");
    return static_cast<int>(result);
}

void convert_from_int(const std::string &base) {
    int i = parse_int(base);
    float f = static_cast<float>(i);
    char c = static_cast<char>(i);
    double d = static_cast<double>(i);
    print_result(c, i, f, d);
}

static float parse_float(const std::string &base) {
    char *end;
    errno = 0;
    float result = std::strtof(base.c_str(), &end);
    if (errno != 0 || *end != 'f' || *(++end) != '\0')
        throw std::invalid_argument("invalid float");
    return (result);
}

void convert_from_float(const std::string &base) {
    float f = parse_float(base);
    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
    double d = static_cast<double>(f);
    print_result(c, i, f, d);
}

static double parse_double(const std::string &base) {
    char *end;
    errno = 0;
    double result = std::strtod(base.c_str(), &end);
    if (errno != 0 || *end != '\0')
        throw std::invalid_argument("invalid double");

    return (result);
}

void convert_from_double(const std::string &base) {
    double d = parse_double(base);
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);
    print_result(c, i, f, d);
}

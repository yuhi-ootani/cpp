

#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp

#include <cctype> //isdigit
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

typedef enum e { e_char, e_int, e_float, e_double, e_pseudo_float, e_pseudo_double } e_literal;

typedef struct s_info {
    bool has_dot;
    bool is_float;
} nbr_info;

class ScalarConverter {
  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

  public:
    static void convert(const std::string &base);
};

// prototype
void print_result(const char &c, const int &i, const float &f, const double &d);
int pseudo_literals_match(const std::string &str, const std::string *lists);
e_literal detect_type(const std::string &base);

// convert_funs
void convert_from_char(const std::string &base);
void convert_from_int(const std::string &base);
void convert_from_float(const std::string &base);
void convert_from_double(const std::string &base);
void print_pseudo_float(const std::string &base);
void print_pseudo_double(const std::string &base);

static void (*const convert_funs[])(const std::string &base) = {
    &convert_from_char,   &convert_from_int,   &convert_from_float,
    &convert_from_double, &print_pseudo_float, &print_pseudo_double};

static const std::string float_lists[] = {"-inff", "+inff", "nanf"};

static const std::string double_lists[] = {"-inf", "+inf", "nan"};

#endif

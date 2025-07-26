

#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp

#include <cstdlib>
#include <iostream>
#include <string>

typedef enum e { e_char, e_int, e_float, e_double, e_error } e_literal;

typedef struct s_info {
    bool valid;
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

#endif

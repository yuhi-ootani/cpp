

#include "ScalarConverter.hpp"

/////////////////////////////////////
//////// print function ////////////
/////////////////////////////////////

static void print_char(const char &c, const int &i) {
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) {
        std::cout << "char:   impossible\n";
    } else if (c == 127 || (c >= 0 && c <= 31))
        std::cout << "char:   "
                  << "Non displayable"
                  << "\n";
    else
        std::cout << "char:   " << c << "\n";
}

// fixed: Don’t use scientific. Always print in normal decimal.
// std::setprecision(N): Changes how many digits are printed after the decimal point.

void print_result(const char &c, const int &i, const float &f, const double &d) {
    // char
    print_char(c, i);

    // int
    std::cout << "int:    " << i << "\n";

    // float: 7 significant digits
    {
        std::ostringstream oss;
        oss << std::setprecision(7) << f; // no fixed!
        std::cout << "float:  " << oss.str() << "f\n";
    }

    // double: 16 significant digits
    {
        std::ostringstream oss;
        oss << std::setprecision(16) << d; // no fixed!
        std::cout << "double: " << oss.str() << "\n";
    }
}
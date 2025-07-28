

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

void print_result(const char &c, const int &i, const float &f, const double &d) {

    // char
    print_char(c, i);

    // int
    std::cout << "int:    " << i << "\n";

    // float
    if (std::floor(f) == f)
        std::cout << "float:  " << f << ".0f\n";
    else
        std::cout << "float:  " << f << "f\n";

    // double
    if (std::floor(d) == d)
        std::cout << "double: " << d << ".0\n";
    else
        std::cout << "double: " << d << "\n";
}

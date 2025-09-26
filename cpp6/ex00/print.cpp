

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
        std::cout << "char:   \'" << c << "\'\n";
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
        oss << std::setprecision(7) << f;
        std::string s = oss.str();
        if (s.find('.') != std::string::npos && s.find('e') == std::string::npos)
            std::cout << "float:  " << oss.str() << "f\n";
        else {
            std::ostringstream oss2;
            oss2 << std::fixed << std::setprecision(1) << f;
            std::cout << "float:  " << oss2.str() << "f\n";
        }
    }

    // double: 16 significant digits
    {
        std::ostringstream oss;
        oss << std::setprecision(16) << d;
        std::string s = oss.str();

        if (s.find('.') != std::string::npos && s.find('e') == std::string::npos) {
            std::cout << "double: " << s << "\n";
        } else {
            std::ostringstream oss2;
            oss2 << std::fixed << std::setprecision(1) << d;
            std::cout << "double: " << oss2.str() << "\n";
        }
    }
}

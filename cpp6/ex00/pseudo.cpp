
#include "ScalarConverter.hpp"

void print_pseudo_float(const std::string &base) {
    int pseudo_index = pseudo_literals_match(base, float_lists);
    std::cout << "char:   impossible\n"
              << "int:    impossible\n"
              << "float:  " << base << "\n"
              << "double: " << double_lists[pseudo_index] << "\n";
}

void print_pseudo_double(const std::string &base) {
    int pseudo_index = pseudo_literals_match(base, double_lists);
    std::cout << "char:   impossible\n"
              << "int:    impossible\n"
              << "float:  " << float_lists[pseudo_index] << "\n"
              << "double: " << base << "\n";
}

int pseudo_literals_match(const std::string &str, const std::string *lists) {

    for (unsigned int i = 0; i < sizeof(float_lists) / sizeof(float_lists[0]); i++) {
        if (str == lists[i])
            return static_cast<int>(i);
    }
    return -1;
}

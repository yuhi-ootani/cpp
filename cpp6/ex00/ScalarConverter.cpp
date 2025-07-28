

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { std::cout << "ScalarConverter default constructor\n"; }

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
    std::cout << "ScalarConverter copy constructor (nothing happen) \n";
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    std::cout << "ScalarConverter operator assignment (nothing happen) \n";
    return *this;
}

ScalarConverter::~ScalarConverter() { std::cout << "ScalarConverter destructor \n"; }

void ScalarConverter::convert(const std::string &base) {
    try {
        e_literal type = detect_type(base);
        // std::cout << "type is " << type << "\n";
        convert_funs[type](base);
    } catch (std::invalid_argument &e) {
        std::cout << "char:   impossible\n"
                  << "int:    impossible\n"
                  << "float:  impossible\n"
                  << "double: impossible\n"
                  << "error:  " << e.what() << "\n ";
    }
}

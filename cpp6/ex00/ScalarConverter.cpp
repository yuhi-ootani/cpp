

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { std::cout << "ScalarConverter default constructor\n"; }

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    std::cout << "ScalarConverter copy constructor (nothing happen) \n";
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    std::cout << "ScalarConverter operator assignment (nothing happen) \n";
}

ScalarConverter::~ScalarConverter() { std::cout << "ScalarConverter destructor \n"; }

/////////////////////////////////////
//////// helper function ////////////
/////////////////////////////////////

bool is_char_type(const std::string &str) {
    if (str.size() == 3) {
        if (str[0] == '\'' && str[2] == '\'') {
            return true;
        }
    }
    return false;
}

static const std::string float_lists[] = {"-inff", "+inff", "nanf"};

static const std::string double_lists[] = {"-inf", "+inf", "nan"};

bool pseudo_literals_match(const std::string &str, const e_literal &type) {
    const std::string *lists = NULL;

    if (type == e_float)
        lists = float_lists;
    else
        lists = double_lists;

    for (int i = 0; i < sizeof(lists) / sizeof(lists[0]); i++) {
        if (str == lists[i])
            return true;
    }
    return false;
}

nbr_info detect_number(const std::string &str) {
    nbr_info nbr = {false, false, false};
    int i = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;

    int size = str.size();
    if (str[str.size()] == 'f') {
        size--;
        nbr.is_float = true;
    }

    std::string::size_type dot_pos = str.find('.');
    if (str.find('.') != std::string::npos)
        return nbr;
    else if (dot_pos == i || dot_pos == (size - 1))
        return nbr;
    nbr.has_dot = true;

    for (; i < size; i++) {
        if (!std::isdigit(str[i]) && str[i] != '.') {
            return nbr;
        }
    }
    nbr.valid = true;
    return nbr;
}

e_literal detect_type(const std::string &base) {
    if (is_char_type(base))
        return e_char;

    if (pseudo_literals_match(base, e_float))
        return e_float;
    if (pseudo_literals_match(base, e_double))
        return e_double;

    nbr_info nbr = detect_number(base);
    if (nbr.valid == false)
        return e_error;
    else if (!nbr.has_dot && !nbr.is_float)
        return e_int;
    else if (nbr.has_dot && nbr.is_float)
        return e_float;
    else if (nbr.has_dot && !nbr.is_float)
        return e_double;
    return e_error;
}

void print_char(const std::string &base) {

    if (base.size() > 2) {
        std::cout << "char: impossible\n";
        return;
    }

    char char0 = base[0];
    if (char0 == 127 || (char0 >= 0 && char0 <= 31)) {
        std::cout << "char: Non displayable";
        return;
    }
}

void print_int(const std::string &base) {}

void print_float(const std::string &base) {}

void print_double(const std::string &base) {}

void ScalarConverter::convert(const std::string &base) {
    e_literal type = detect_type(base);
    
    print_char(base);
    print_int(base);
    print_float(base);
    print_double(base);
}

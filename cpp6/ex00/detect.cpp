
#include "ScalarConverter.hpp"

/////////////////////////////////////
//////// detect function ////////////
/////////////////////////////////////

static bool is_char_type(const std::string &str) {
    if (str.size() == 3) {
        if (str[0] == '\'' && str[2] == '\'') {
            return true;
        }
    }
    return false;
}

static nbr_info detect_number(const std::string &str) {
    nbr_info nbr = {false, false};
    // std::string::size_type is the unsigned integer type
    std::string::size_type i = 0;
    std::string::size_type size = str.size();

    if (str[0] == '-' || str[0] == '+')
        i++;

    if (!std::isdigit(str[i])) {
        throw std::invalid_argument("number doesn't start as digit");
    }

    std::string::size_type dot_pos = str.find('.');
    if (dot_pos != std::string::npos) {
        if (size > 0 && str[size - 1] == 'f') {
            size--;
            nbr.is_float = true;
        }

        if (str.find('.', dot_pos + 1) != std::string::npos) {
            throw std::invalid_argument("has two dots");
        } else if (dot_pos == i || dot_pos == (size - 1)) {
            throw std::invalid_argument("start and ends with dot");
        }
        nbr.has_dot = true;
    }

    for (; i < size; i++) {
        if (!std::isdigit(str[i]) && str[i] != '.') {
            throw std::invalid_argument("invalid character inside number");
        }
    }

    return nbr;
}

e_literal detect_type(const std::string &base) {
    if (base.empty())
        throw std::invalid_argument("empty literal");

    if (is_char_type(base))
        return e_char;

    if (pseudo_literals_match(base, float_lists) != -1)
        return e_pseudo_float;
    if (pseudo_literals_match(base, double_lists) != -1)
        return e_pseudo_double;

    nbr_info nbr = detect_number(base);

    if (!nbr.has_dot && !nbr.is_float)
        return e_int;
    else if (nbr.has_dot && nbr.is_float)
        return e_float;
    else if (nbr.has_dot && !nbr.is_float)
        return e_double;
    throw std::invalid_argument("does not match any type");
}

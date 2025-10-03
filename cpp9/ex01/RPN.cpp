
#include "RPN.hpp"

RPN::RPN() : _stack() {}

RPN::RPN(const char *arg1) {
    std::string formula(arg1);
    if (!validateStr(formula))
        throw std::runtime_error("invalid formula");
}

RPN::RPN(const RPN &other) {
    if (this != &other) {
        *this = other;
    }
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::validateStr(const std::string &formula) const {
    if (formula.find_first_not_of("0123456789+-/* ") != std::string::npos)
        return false;

    
}
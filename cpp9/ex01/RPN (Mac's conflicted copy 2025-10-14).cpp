
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

static bool isOpe(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

bool RPN::validateStr(const std::string &formula) const {
    if (formula.empty())
        return false;

    std::istringstream iss(formula);
    std::string token;
    int depth = 0;

    while (iss >> token) {
        if (token.size() != 1)
            return false;

        unsigned char c = static_cast<unsigned char>(token[0]);
        if (std::isdigit(c)) {
            ++depth;
        } else if (isOpe(c)) {
            if (depth < 2)
                return false;
            --depth;
        } else {
            return false;
        }
    }
    return (depth == 1);
}

int RPN::calculate(char ope) {
    if (_stack.size() < 2)
        throw std::runtime_error("stack underflow");

    int right = _stack.top();
    _stack.pop();
    int left = _stack.top();
    _stack.pop();

    const int IMAX = std::numeric_limits<int>::max();
    const int IMIN = std::numeric_limits<int>::min();

    int res = 0;
    switch (ope) {
    case '+': {
        long tmp = static_cast<long>(left) + static_cast<long>(right);
        if (tmp > IMAX || tmp < IMIN) {
            throw std::overflow_error("integer overflow on addition");
            std::cerr << left << " + " << right << " = " << tmp << std::endl;
        }
        res = static_cast<int>(tmp);
        break;
    }
    case '-': {
        long tmp = static_cast<long>(left) - static_cast<long>(right);
        if (tmp > IMAX || tmp < IMIN) {
            std::cerr << left << " - " << right << " = " << tmp << std::endl;
            throw std::overflow_error("integer overflow on subtraction");
        }
        res = static_cast<int>(tmp);
        break;
    }
    case '*': {
        long tmp = static_cast<long>(left) * static_cast<long>(right);
        if (tmp > IMAX || tmp < IMIN) {
            std::cerr << left << " * " << right << " = " << tmp << std::endl;
            throw std::overflow_error("integer overflow on multiplication");
        }
        res = static_cast<int>(tmp);
        break;
    }
    case '/': {
        if (right == 0)
            throw std::out_of_range("division by zero");
        long tmp = static_cast<long>(left) * static_cast<long>(right);
        if (left == IMIN && right == -1) {
            std::cerr << left << " / " << right << " = " << tmp << std::endl;
            throw std::overflow_error("integer overflow on division");
        }
        res = left / right;
        break;
    }
    default:
        throw std::runtime_error("unknown operator");
    }
    return res;
}

void RPN::ReversePolishNotation(const std::string &formula) {
    std::istringstream iss(formula);
    std::string token;

    int res;

    while (iss >> token) {
        unsigned char c = static_cast<unsigned char>(token[0]);

        if (std::isdigit(c)) {
            int val = static_cast<int>(c - '0');
            _stack.push(val);
        } else if (isOpe(c)) {
            res = calculate(c);
            _stack.push(res);
        } else {
            throw std::runtime_error("unknown operator");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("leftover stack items");
    std::cout << res << std::endl;
}

void RPN::execute(const std::string &formula) {
    if (!validateStr(formula))
        throw std::out_of_range("invalid format");
    ReversePolishNotation(formula);
}


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
    int right = _stack.top();
    _stack.pop();
    int left = _stack.top();
    _stack.pop();

    int res;
    switch (ope) {
    case '+':
        if ((right > 0 && left > INT_MAX - right) || (right < 0 && left < INT_MIN - right)) {
            throw std::overflow_error("integer overflow on addition");
        }
        res = left + right;
        break;
    case '-':
        if ((right < 0 && left > INT_MAX + right) || (right > 0 && left < INT_MIN + right)) {
            throw std::overflow_error("integer overflow on subtraction");
        }
        res = left - right;
        break;
    case '*':
        if (right != 0 && (left > INT_MAX / right || left < INT_MIN / right)) {
            throw std::overflow_error("integer overflow on multiplication");
        }
        res = left * right;
        break;
    case '/':
        if (right == 0)
            throw std::out_of_range("division by zero");
        res = left / right;
        break;
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

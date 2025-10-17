#ifndef RPN_HPP
#define RPN_HPP

// https://k144.github.io/tools/rpn/

#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN {
  private:
    std::stack<int> _stack;

  public:
    RPN();
    RPN(const char *formula);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    bool validateStr(const std::string &formula) const;
    void ReversePolishNotation(const std::string &formula);
    int calculate(char ope);
    void execute(const std::string &formula);
};

#endif

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

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
};

#endif
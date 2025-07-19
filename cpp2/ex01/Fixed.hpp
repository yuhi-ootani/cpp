
#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <string>

class Fixed {
  private:
    int _value;
    static const int _fixed_point = 8;

  public:
    Fixed();
    Fixed(const Fixed &original);
    Fixed &operator=(const Fixed &original);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    // ex01
    Fixed(const int int_value);
    Fixed(const float float_value);
    float toFloat(void) const;
    int toInt(void) const;
};

// A free function lets the left operand be the stream (std::cout) and the right operand be our
// object. like std::cout << myFixed;
std::ostream &operator<<(std::ostream &os, const Fixed &f);
// std::ostream &os
// This is the output stream you’re writing into (for example, std::cout

#endif

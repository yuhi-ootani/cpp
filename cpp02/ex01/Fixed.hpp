
#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <string>

class Fixed {
  private:
    int _value;
    static const int _fixed_point;

  public:
    Fixed();
    Fixed(const int &int_value);
    Fixed(const float &float_value);
    Fixed(const Fixed &original);
    Fixed &operator=(const Fixed &original);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif

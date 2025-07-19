
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
  private:
    int _value;
    // static :There is exactly one single _fixed_point shared by all instances of Fixed.
    // static const integral types (e.g. int, char, bool) are allowed an in-class initialier.
    static const int _fixed_point = 8;

  public:
    Fixed();
    Fixed(const Fixed &original);
    Fixed &operator=(const Fixed &original);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif

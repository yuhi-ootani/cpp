
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>


class Fixed {
  private:
    int _value;
    static const int _fixed_point;

  public:
    Fixed();
    Fixed(const Fixed &original);
    Fixed &operator=(const Fixed &original);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};



#endif

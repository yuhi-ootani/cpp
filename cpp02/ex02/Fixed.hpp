
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

    // ex02
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    Fixed operator+(const Fixed &original);
    Fixed operator-(const Fixed &original);
    Fixed operator*(const Fixed &original);
    Fixed operator/(const Fixed &original);
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);
    // static (it belongs to the class and does not need to make instance to call)
    static Fixed &min(Fixed &fa, Fixed &fb);
    static Fixed &min(const Fixed &fa, const Fixed &fb);
    static Fixed &max(Fixed &fa, Fixed &fb);
    static Fixed &max(const Fixed &fa, const Fixed &fb);
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

bool Fixed::operator>(const Fixed &other) const { return this->_value > other._value; };

bool Fixed::operator<(const Fixed &other) const { return this->_value > other._value; };

bool Fixed::operator>=(const Fixed &other) const { return this->_value >= other._value; };

bool Fixed::operator<=(const Fixed &other) const { return this->_value >= other._value; };

bool Fixed::operator==(const Fixed &other) const { return this->_value == other._value; };

bool Fixed::operator!=(const Fixed &other) const { return this->_value != other._value; };

#endif

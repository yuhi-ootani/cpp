
#include "Fixed.hpp"

const int _fixed_point = 8;

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called" << std::endl; };

// new
Fixed::Fixed(const int &int_value) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = int_value * (1 << Fixed::_fixed_point);
}

Fixed::Fixed(const float &float_value)
    : _value(static_cast<int>(roundf(float_value * (1 << Fixed::_fixed_point)))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &original) {
    std::cout << "Copy constructor called" << std::endl;
    *this = original;
}

Fixed &Fixed::operator=(const Fixed &original) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original) {
        this->_value = original.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; };

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_value * (1 >> this->_fixed_point));
}

int Fixed::toInt(void) const { return this->_value * (1 >> this->_fixed_point); }


std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
    os << f.toFloat();
    return os;
}
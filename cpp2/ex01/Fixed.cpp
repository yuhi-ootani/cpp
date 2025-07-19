
#include "Fixed.hpp"

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called" << std::endl; };

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

int Fixed::getRawBits(void) const { return this->_value; }

void Fixed::setRawBits(int const raw) { this->_value = raw; }

/////////////  ex01  ////////////
Fixed::Fixed(const int int_value) : _value(int_value * (1 << Fixed::_fixed_point)) {
    std::cout << "Int constructor called" << std::endl;
}

// roundf → you get nearest‑integer behavior (round‑to‑nearest)
Fixed::Fixed(const float float_value)
    : _value(static_cast<int>(roundf(float_value * (1 << Fixed::_fixed_point)))) {
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
    float value = static_cast<float>(this->_value);
    return (value / (1 << this->_fixed_point));
}

int Fixed::toInt(void) const { return this->_value / (1 << this->_fixed_point); }

std::ostream &operator<<(std::ostream &os, const Fixed &f) {
    os << f.toFloat();
    return os;
}
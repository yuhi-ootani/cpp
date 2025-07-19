
#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    // std::cout << "Default constructor called" << std::endl;
    ;
}

Fixed::Fixed(const Fixed &original) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = original;
}

Fixed &Fixed::operator=(const Fixed &original) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original) {
        this->_value = original.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
    ;
}

int Fixed::getRawBits(void) const { return this->_value; }

void Fixed::setRawBits(int const raw) { this->_value = raw; }

/////////////////// ex01 ////////////////////////////
Fixed::Fixed(const int int_value) : _value(int_value * (1 << Fixed::_fixed_point)) {
    // std::cout << "Int constructor called" << std::endl;
    ;
}

Fixed::Fixed(const float float_value)
    : _value(static_cast<int>(roundf(float_value * (1 << Fixed::_fixed_point)))) {
    // std::cout << "Float constructor called" << std::endl;
    ;
}

float Fixed::toFloat(void) const {
    float float_value = static_cast<float>(this->_value);
    return (float_value / (1 << this->_fixed_point));
}

int Fixed::toInt(void) const { return this->_value / (1 << this->_fixed_point); };

// non-member function
std::ostream &operator<<(std::ostream &os, const Fixed &f) {
    os << f.toFloat();
    return os;
}

/////////////////// ex02 ////////////////////////////
// ——— Comparisons ———
bool Fixed::operator>(const Fixed &other) const { return this->_value > other._value; }

bool Fixed::operator<(const Fixed &other) const { return this->_value < other._value; }

bool Fixed::operator>=(const Fixed &other) const { return this->_value >= other._value; }

bool Fixed::operator<=(const Fixed &other) const { return this->_value <= other._value; }

bool Fixed::operator==(const Fixed &other) const { return this->_value == other._value; }

bool Fixed::operator!=(const Fixed &other) const { return this->_value != other._value; }

// ——— Arithmetic ———
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed temp(this->toFloat() + other.toFloat());
    return temp;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed temp(this->toFloat() - other.toFloat());
    return temp;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed temp(this->toFloat() * other.toFloat());
    return temp;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed temp(this->toFloat() / other.toFloat());
    return temp;
}

// ——— Increment / Decrement ———
Fixed &Fixed::operator++() {
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed old = *this;
    this->_value++;
    return old;
}

Fixed &Fixed::operator--() {
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed old = *this;
    this->_value--;
    return old;
}

Fixed &Fixed::min(Fixed &fa, Fixed &fb) {
    if (fa < fb)
        return (fa);
    return (fb);
}

Fixed &Fixed::max(Fixed &fa, Fixed &fb) {
    if (fa > fb)
        return (fa);
    return (fb);
}

const Fixed &Fixed::min(const Fixed &fa, const Fixed &fb) {
    if (fa < fb)
        return (fa);
    return (fb);
}

const Fixed &Fixed::max(const Fixed &fa, const Fixed &fb) {
    if (fa > fb)
        return (fa);
    return (fb);
}

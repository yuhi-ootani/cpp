
#include "Fixed.hpp"

const int Fixed::_fixed_point = 8;

Fixed::Fixed() : _value(0) {
    // std::cout << "Default constructor called" << std::endl;
    ;
};

// ex01
Fixed::Fixed(const int &int_value) : _value(int_value * (1 << Fixed::_fixed_point)) {
    // std::cout << "Int constructor called" << std::endl;
    ;
};

// ex01
Fixed::Fixed(const float &float_value)
    : _value(static_cast<int>(roundf(float_value * (1 << Fixed::_fixed_point)))) {
    // std::cout << "Float constructor called" << std::endl;
    ;
};

Fixed::Fixed(const Fixed &original) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = original;
};

Fixed &Fixed::operator=(const Fixed &original) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original) {
        this->_value = original.getRawBits();
    }
    return *this;
};

Fixed::~Fixed() {
    ;
    // std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const { return this->_value; };

void Fixed::setRawBits(int const raw) { this->_value = raw; };

float Fixed::toFloat(void) const {
    float value = static_cast<float>(this->_value);
    return (value / (1 << this->_fixed_point));
};

int Fixed::toInt(void) const { return this->_value / (1 << this->_fixed_point); };

// ex02

bool Fixed::operator>(const Fixed &other) const { return this->_value > other._value; };

bool Fixed::operator<(const Fixed &other) const { return this->_value < other._value; };

bool Fixed::operator>=(const Fixed &other) const { return this->_value >= other._value; };

bool Fixed::operator<=(const Fixed &other) const { return this->_value <= other._value; };

bool Fixed::operator==(const Fixed &other) const { return this->_value == other._value; };

bool Fixed::operator!=(const Fixed &other) const { return this->_value != other._value; };

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed temp(this->_value + other._value);
    return temp;
};

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed temp(this->_value - other._value);
    return temp;
};

Fixed Fixed::operator*(const Fixed &other) {
    Fixed temp;
    long long wide = static_cast<long long>(this->_value * other._value);
    temp._value = static_cast<int>(wide >> temp._fixed_point);
    return temp;
};

Fixed Fixed::operator/(const Fixed &other) const {
    float f1 = this->toFloat();
    float f2 = other.toFloat();
    return Fixed(f1 / f2);
};

Fixed &Fixed::operator++() {
    this->_value++;
    return *this;
};

Fixed Fixed::operator++(int) {
    Fixed old = *this;
    this->_value++;
    return old;
};

Fixed &Fixed::operator--() {
    this->_value--;
    return *this;
};

Fixed Fixed::operator--(int) {
    Fixed old = *this;
    this->_value++;
    return old;
};

Fixed &Fixed::min(Fixed &fa, Fixed &fb) { return fa._value < fb._value ? fa : fb; };

const Fixed &Fixed::min(const Fixed &fa, const Fixed &fb) {
    return fa._value < fb._value ? fa : fb;
};

Fixed &Fixed::max(Fixed &fa, Fixed &fb) { return fa._value > fb._value ? fa : fb; };

const Fixed &Fixed::max(const Fixed &fa, const Fixed &fb) {
    return fa._value > fb._value ? fa : fb;
};

// non-member function
std::ostream &operator<<(std::ostream &os, const Fixed &f) {
    os << f.toFloat();
    return os;
};

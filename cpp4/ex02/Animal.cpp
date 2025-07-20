
#include "Animal.hpp"

Animal::Animal() : _type("Unknown") {
    std::cout << "Animal of type \"" << _type << "\" constructed (default)\n";
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << "Animal copy‑constructed from type \"" << other._type << "\"\n";
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other)
        this->_type = other._type;
    std::cout << "Animal copy‑assignment called, new type = " << other._type << std::endl;
    return *this;
}

Animal::~Animal() { std::cout << "Animal of type \"" << _type << "\" destroyed.\n"; }

std::string Animal::getType() const { return _type; }
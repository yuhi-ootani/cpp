

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown") {
    std::cout << "WrongAnimal of type \"" << _type << "\" constructed (default)\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
    std::cout << "WrongAnimal copy‑constructed from type \"" << other._type << "\"\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other)
        this->_type = other._type;
    std::cout << "WrongAnimal copy‑assignment called, new type = " << other._type << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal of type \"" << _type << "\" destroyed.\n"; }

void WrongAnimal::makeSound() const { std::cout << _type << " makes a sound.\n"; }

std::string WrongAnimal::getType() const { return _type; }

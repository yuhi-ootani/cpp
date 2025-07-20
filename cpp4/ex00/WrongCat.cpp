

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    _type = "WrongCat";
    std::cout << "WrongCat of type \"" << _type << "\" constructed (default)\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << "WrongCat copy‑constructed from type \"" << other._type << "\"\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std::cout << "WrongCat copy‑assignment called, new type = " << other._type << std::endl;
    return *this;
}

WrongCat::~WrongCat() { std::cout << "WrongCat of type \"" << _type << "\" destroyed.\n"; }

void WrongCat::makeSound() const { std::cout << _type << " says: Meow! Meow!\n"; }


#include "Cat.hpp"

Cat::Cat() : Animal() {
    _type = "Cat";
    std::cout << "Cat of type \"" << _type << "\" constructed (default)\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy‑constructed from type \"" << other._type << "\"\n";
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Cat copy‑assignment called, new type = " << _type << std::endl;
    return *this;
}

Cat::~Cat() { std::cout << "Cat of type \"" << _type << "\" deconstructed.\n"; }

void Cat::makeSound() const { std::cout << _type << " says: Meow! Meow!\n"; }
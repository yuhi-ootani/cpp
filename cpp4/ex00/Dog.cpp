
#include "Dog.hpp"

Dog::Dog() : Animal() {
    _type = "Dog";
    std::cout << "Dog of type \"" << _type << "\" constructed (default)\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy‑constructed from type \"" << other._type << "\"\n";
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Dog copy‑assignment called, new type = " << other._type << std::endl;
    return *this;
}

Dog::~Dog() { std::cout << "Dog of type \"" << _type << "\" destroyed.\n"; }

void Dog::makeSound() const { std::cout << _type << " says: Woof! Woof!\n"; }

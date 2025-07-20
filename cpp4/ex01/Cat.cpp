
#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain()) {
    std::cout << "Cat of type \"" << _type << "\" constructed (default)\n";
    _type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain)) {
    std::cout << "Cat copy‑constructed from type \"" << other._type << "\"\n";
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat copy‑assignment called, new type = " << other._type << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *_brain = *other._brain;
    }
    return *this;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat of type \"" << _type << "\" destroyed.\n";
}

void Cat::makeSound() const { std::cout << _type << " says: Meow! Meow!\n"; }

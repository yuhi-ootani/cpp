
#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain()) {
    _type = "Dog";
    std::cout << "Dog of type \"" << _type << "\" constructed (default)\n";
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain)) {
    std::cout << "Dog copy‑constructed from type \"" << other._type << "\"\n";
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        *_brain = *other._brain;
    }
    std::cout << "Dog copy‑assignment called, new type = " << other._type << std::endl;
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog of type \"" << _type << "\" destroyed.\n";
}

void Dog::makeSound() const { std::cout << _type << " says: Woof! Woof!\n"; }

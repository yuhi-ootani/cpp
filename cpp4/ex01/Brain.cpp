
#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain constructed (default)\n"; }

Brain::Brain(const Brain &other) {
    *this = other;
    std::cout << "Brain copy-constructed called.\n";
}

Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    std::cout << "Brain copy-assignment called.\n";
    return *this;
}

Brain::~Brain() { std::cout << "Brain destructed.\n"; }


#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::~Zombie(void) { std::cout << name_ << " is destroyed." << std::endl; };

void Zombie::announce(void) { std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl; }
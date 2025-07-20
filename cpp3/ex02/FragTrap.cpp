
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << "FragTrap " << _name << " constructed(default constructor)!\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << "FragTrap " << _name << " constructed.\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap Copy constructor called.\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap assignment operator called.\n";
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// destructor definitions don’t take initializer lists at all.
FragTrap::~FragTrap() { std::cout << "FragTrap " << _name << " destroyed!\n"; };

void FragTrap::highFivesGuys() {
    if (_hit_points == 0) {
        std::cout << "FragTrap " << _name << " is down and can't high-five.\n";
    } else {
        std::cout << "FragTrap " << _name << " requests a HIGH FIVE! ✋\n";
    }
}
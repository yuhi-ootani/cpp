
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap " << _name << " constructed(default constructor)!\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap " << _name << " constructed.\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap Copy constructor called.\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap assignment operator called.\n";
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// destructor definitions don’t take initializer lists at all.
ScavTrap::~ScavTrap() { std::cout << "ScavTrap " << _name << " destroyed!\n"; };

void ScavTrap::attack(const std::string &target) {
    if (_hit_points <= 0 || _energy_points <= 0) {
        std::cout << "ScavTrap " << _name << " doesn't have enough points to attack.\n";
        return;
    }
    _energy_points--;
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage
              << " points of damage!\n";
}

void ScavTrap::guardGate() {
    if (_hit_points <= 0) {
        std::cout << "ScavTrap " << _name << " doesn't have enough points to guard.\n";
        return;
    }

    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode.\n";
}

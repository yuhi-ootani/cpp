
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unnamed"), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "ClapTrap " << _name << " constructed (default constructor)!\n";
}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "ClapTrap " << name << " constructed.\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "ClapTrap Copy constructor called.\n";
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap Copy assignment operator called.\n";
    if (this != &other) {
        _name = other._name;
        _hit_points = other._hit_points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap " << _name << " destroyed!\n"; };

void ClapTrap::attack(const std::string &target) {
    if (_hit_points <= 0 || _energy_points <= 0) {
        std::cout << _name << " doesn't have enough points to attack.\n";
        return;
    }
    _energy_points--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage
              << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hit_points <= 0) {
        std::cout << "ClapTrap " << _name << " is already destroyed and can't take more damage.\n";
        return;
    }

    if (amount >= _hit_points) {
        _hit_points = 0;
    } else {
        _hit_points -= amount;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! ("
              << _hit_points << " HP remaining)\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hit_points <= 0 || _energy_points <= 0) {
        std::cout << _name << " doesn't have enough points to repair.\n";
        return;
    }
    _energy_points--;
    _hit_points += amount;
    std::cout << "ClapTrap " << _name << " repairs " << amount << " points of HP! (" << _hit_points
              << " HP remaining)\n";
}
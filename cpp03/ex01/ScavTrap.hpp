
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap {
  public:
    ScavTrap(const std::string &name) : ClapTrap(name) {
        _hit_points = 100;
        _energy_points = 50;
        _attack_damage = 20;
        std::cout << "ScavTrap " << name << " constructed.\n";
    }
};

#endif
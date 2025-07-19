
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() { delete _weapon; }

void HumanB::setWeapon(Weapon weapon) {
    delete _weapon;
    _weapon = new Weapon(weapon);
}

void HumanB::attack() const {
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " is unarmed!\n";
}
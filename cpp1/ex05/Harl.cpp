
#include "Harl.hpp"

// You don’t repeat static (that belongs only in the declaration), but you do repeat const so that
// the definition exactly matches the declared type.
const char *Harl::_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
const Harl::HarlFoo Harl::_actions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

void Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup "
                 "burger. I really do!"
              << std::endl;
}

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough "
                 "bacon in my burger! If you did, I wouldn't be asking for more!"
              << std::endl;
}

void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, "
                 "whereas you started working here just last month."
              << std::endl;
}

void Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    for (int i = 0; i < Harl::NUM_LEVELS; i++) {
        if (Harl::_levels[i] == level) {
            (this->*_actions[i])();
            return;
        }
    }
}
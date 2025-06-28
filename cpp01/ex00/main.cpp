
#include "Zombie.hpp"

int main() {
    Zombie *zombie = newZombie("Zombie1");
    zombie->announce();

    randomChump("Zombie2");

    delete zombie;
    return 0;
}
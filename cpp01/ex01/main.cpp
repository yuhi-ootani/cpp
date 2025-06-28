
#include "Zombie.hpp"

int main() {
    Zombie *horde = zombieHorde(5, "ZombieHorde");
    for (int i = 0; i < 5; ++i) {
        horde[i].announce();
    }
    delete[] horde;
    horde = NULL;
    return 0;
}
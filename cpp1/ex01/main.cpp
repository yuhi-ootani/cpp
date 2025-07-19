
#include "Zombie.hpp"

int main() {
    const int N = 6;
    Zombie *horde = zombieHorde(N, "ZombieHorde");
    if (!horde) {
        std::cerr << "Failed to allocate a zombie horde of size " << N << "\n";
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }

    delete[] horde;
    horde = NULL;
    return 0;
}
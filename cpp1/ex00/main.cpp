
#include "Zombie.hpp"

int main() {
    Zombie one("Bob");
    Zombie two("Lee");
    Zombie *three = newZombie("Jon");

    three->announce();
    two.announce();
    randomChump("Sam");
    one.announce();
    delete three;
}
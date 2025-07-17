
#include "ClapTrap.hpp"

int main() {
    std::cout << "=== ClapTrap Test Program ===" << std::endl;
    std::cout << std::endl;

    // Test 1: Constructor and basic functionality
    std::cout << "--- Test 1: Constructor and Basic Operations ---" << std::endl;
    ClapTrap clap1("Clappy");

    clap1.attack("Enemy1");
    clap1.takeDamage(3);
    clap1.beRepaired(2);
    std::cout << std::endl;

    // Test 2: Energy depletion
    std::cout << "--- Test 2: Energy Depletion ---" << std::endl;
    ClapTrap clap2("Energetic");

    // Perform 10 attacks to deplete energy
    for (int i = 1; i <= 10; i++) {
        std::ostringstream oss; // an std::ostream that writes into an internal std::string buffer
        oss << i;               // write the integer into the stream
        std::string idx = oss.str(); // extract as string

        std::string target = "Target"; // base name
        target += idx;                 // append the number
        std::cout << "Attack " << i << ": ";
        clap2.attack(target);
    }

    // Try to attack when no energy left
    std::cout << "Attempting attack with no energy: ";
    clap2.attack("LastTarget");

    // Try to repair when no energy left
    std::cout << "Attempting repair with no energy: ";
    clap2.beRepaired(5);
    std::cout << std::endl;

    // Test 3: Hit points depletion
    std::cout << "--- Test 3: Hit Points Depletion ---" << std::endl;
    ClapTrap clap3("Fragile");

    // Take damage to reduce hit points
    clap3.takeDamage(5);   // 10 -> 5 HP
    clap3.attack("Enemy"); // Should still work

    clap3.takeDamage(6); // 5 -> 0 HP (actually can't go below 0)

    // Try to attack when no hit points left
    std::cout << "Attempting attack with no hit points: ";
    clap3.attack("Enemy");

    // Try to repair when no hit points left
    std::cout << "Attempting repair with no hit points: ";
    clap3.beRepaired(3);
    std::cout << std::endl;

    // Test 4: Repair functionality
    std::cout << "--- Test 4: Repair Functionality ---" << std::endl;
    ClapTrap clap4("Healer");

    clap4.takeDamage(7);   // 10 -> 3 HP
    clap4.beRepaired(4);   // 3 -> 7 HP
    clap4.attack("Enemy"); // Should work normally
    std::cout << std::endl;

    // Test 5: Edge cases
    std::cout << "--- Test 5: Edge Cases ---" << std::endl;
    ClapTrap clap5("EdgeCase");

    // Take more damage than current HP
    clap5.takeDamage(15); // Should not go below 0

    // Try to repair when dead
    clap5.beRepaired(5);
    std::cout << std::endl;

    // Test 6: Copy constructor (if implemented)
    std::cout << "--- Test 6: Copy Constructor ---" << std::endl;
    ClapTrap clap6("Original");
    clap6.takeDamage(2);

    ClapTrap clap6_copy(clap6); // Copy constructor
    clap6_copy.takeDamage(2);
    std::cout << std::endl;

    // Test 7: Multiple ClapTraps
    std::cout << "--- Test 7: Multiple ClapTraps ---" << std::endl;
    ClapTrap army[3] = {ClapTrap("Soldier1"), ClapTrap("Soldier2"), ClapTrap("Soldier3")};

    for (int i = 0; i < 3; i++) {
        army[i].attack("CommonEnemy");
    }
    std::cout << std::endl;

    std::cout << "--- Test Complete: Destructors will be called ---" << std::endl;

    return 0;
}
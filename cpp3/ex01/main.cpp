
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
    std::cout << "=== SCAVTRAP TESTING ===" << std::endl;
    std::cout << std::endl;

    // Test 1: Default constructor
    std::cout << "--- Test 1: Default Constructor ---" << std::endl;
    ScavTrap scav1;
    std::cout << std::endl;

    // Test 2: Parameterized constructor
    std::cout << "--- Test 2: Parameterized Constructor ---" << std::endl;
    ScavTrap scav2("Guardian");
    std::cout << std::endl;

    // Test 3: Copy constructor
    std::cout << "--- Test 3: Copy Constructor ---" << std::endl;
    ScavTrap scav3(scav2);
    std::cout << std::endl;

    // Test 4: Assignment operator
    std::cout << "--- Test 4: Assignment Operator ---" << std::endl;
    ScavTrap scav4;
    scav4 = scav2;
    std::cout << std::endl;

    // Test 5: Display initial stats
    std::cout << "--- Test 5: Initial Stats ---" << std::endl;
    std::cout << "scav1 stats:" << std::endl;
    scav1.attack("target");
    scav1.takeDamage(0);
    scav1.beRepaired(0);
    std::cout << std::endl;

    std::cout << "scav2 (Guardian) stats:" << std::endl;
    scav2.attack("enemy");
    scav2.takeDamage(0);
    scav2.beRepaired(0);
    std::cout << std::endl;

    // Test 6: Attack functionality
    std::cout << "--- Test 6: Attack Functionality ---" << std::endl;
    scav2.attack("Bandit");
    scav2.attack("Psycho");
    scav2.attack("Skag");
    std::cout << std::endl;

    // Test 7: Take damage
    std::cout << "--- Test 7: Take Damage ---" << std::endl;
    scav2.takeDamage(30);
    scav2.takeDamage(25);
    scav2.attack("Wounded enemy");
    std::cout << std::endl;

    // Test 8: Repair
    std::cout << "--- Test 8: Repair ---" << std::endl;
    scav2.beRepaired(20);
    scav2.beRepaired(15);
    scav2.attack("Healed enemy");
    std::cout << std::endl;

    // Test 9: Special ability - Gate keeper mode
    std::cout << "--- Test 9: Gate Keeper Mode ---" << std::endl;
    scav2.guardGate();
    scav3.guardGate();
    scav4.guardGate();
    std::cout << std::endl;

    // Test 10: Energy depletion
    std::cout << "--- Test 10: Energy Depletion ---" << std::endl;
    ScavTrap energyTest("EnergyDrain");

    // ScavTrap starts with 50 energy points
    // Each attack and repair costs 1 energy point
    for (int i = 0; i < 52; i++) {
        std::cout << "Action " << i + 1 << ": ";
        if (i % 2 == 0)
            energyTest.attack("dummy");
        else
            energyTest.beRepaired(1);
    }
    std::cout << std::endl;

    // Test 11: Death scenario
    std::cout << "--- Test 11: Death Scenario ---" << std::endl;
    ScavTrap deathTest("Doomed");
    deathTest.takeDamage(100); // Should bring HP to 0
    deathTest.attack("ghost"); // Should not be able to attack when dead
    deathTest.beRepaired(50);  // Should not be able to repair when dead
    deathTest.guardGate();     // Test special ability when dead
    std::cout << std::endl;

    // Test 12: Massive damage
    std::cout << "--- Test 12: Massive Damage ---" << std::endl;
    ScavTrap massiveDamageTest("Tank");
    massiveDamageTest.takeDamage(150); // More damage than HP
    massiveDamageTest.attack("survivor");
    std::cout << std::endl;

    // Test 13: Multiple gate keeper activations
    std::cout << "--- Test 13: Multiple Gate Keeper Activations ---" << std::endl;
    ScavTrap gateKeeper("Gatekeeper");
    gateKeeper.guardGate();
    gateKeeper.guardGate();
    gateKeeper.guardGate();
    std::cout << std::endl;

    // Test 14: Combat scenario
    std::cout << "--- Test 14: Combat Scenario ---" << std::endl;
    ScavTrap fighter1("Warrior");
    ScavTrap fighter2("Berserker");

    std::cout << "Combat begins!" << std::endl;
    fighter1.attack("Berserker");
    fighter2.takeDamage(20);

    fighter2.attack("Warrior");
    fighter1.takeDamage(20);

    fighter1.beRepaired(10);
    fighter2.beRepaired(10);

    fighter1.guardGate();
    fighter2.guardGate();
    std::cout << std::endl;

    std::cout << "--- Test 15: Destruction Order ---" << std::endl;
    std::cout << "Creating block scope to test destruction..." << std::endl;
    {
        ScavTrap temp1("Temp1");
        ScavTrap temp2("Temp2");
        std::cout << "About to leave scope..." << std::endl;
    }
    std::cout << "Left scope - destructors should have been called" << std::endl;
    std::cout << std::endl;

    std::cout << "=== END OF SCAVTRAP TESTING ===" << std::endl;
    std::cout << "All ScavTrap objects will now be destroyed..." << std::endl;

    return 0;
}
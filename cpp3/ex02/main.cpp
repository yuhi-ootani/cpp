// main.cpp

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Test 1: ClapTrap 
    std::cout << "--- Test 1: ClapTrap ---" << std::endl;
    ClapTrap ct1("CT-One");
    ct1.attack("Dummy");
    ct1.takeDamage(5);
    ct1.beRepaired(3);
    std::cout << std::endl;

    // Test 2: ScavTrap 
    std::cout << "--- Test 2: ScavTrap ---" << std::endl;
    ScavTrap st1("ST-One");
    st1.attack("Dummy");
    st1.guardGate();
    std::cout << std::endl;

    // Test 5: FragTrap の構築・攻撃・ハイファイブ
    std::cout << "--- Test 5: FragTrap ---" << std::endl;
    FragTrap ft1("FT-One");
    ft1.attack("Dummy");
    ft1.highFivesGuys();
    std::cout << std::endl;

    // Test 6: FragTrap のコピーコンストラクタ
    std::cout << "--- Test 6: FragTrap Copy Constructor ---" << std::endl;
    FragTrap ft2(ft1);
    ft2.attack("TargetF");
    ft2.highFivesGuys();
    std::cout << std::endl;

    // Test 7: FragTrap の代入演算子
    std::cout << "--- Test 7: FragTrap Assignment ---" << std::endl;
    FragTrap ft3;
    ft3 = ft1;
    ft3.attack("TargetG");
    ft3.highFivesGuys();
    std::cout << std::endl;

    return 0;
}

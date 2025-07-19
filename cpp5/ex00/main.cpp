#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    // 1) Valid boundary constructions
    std::cout << "\n-- Valid construction at grade = 1 --\n";
    try {
        Bureaucrat high("High", 1);
        std::cout << high << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "\n-- Valid construction at grade = 150 --\n";
    try {
        Bureaucrat low("Low", 150);
        std::cout << low << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    // 2) Invalid constructions
    std::cout << "\n-- Invalid construction grade = 0 --\n";
    try {
        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << tooHigh << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "\n-- Invalid construction grade = 151 --\n";
    try {
        Bureaucrat tooLow("TooLow", 151);
        std::cout << tooLow << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    // 3) Normal gradeUp / gradeDown
    std::cout << "\n-- gradeUp from 2 → 1 --\n";
    try {
        Bureaucrat alice("Alice", 2);
        std::cout << alice << "\n";
        alice.gradeUp();
        std::cout << alice << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "\n-- gradeDown from 149 → 150 --\n";
    try {
        Bureaucrat bob("Bob", 149);
        std::cout << bob << "\n";
        bob.gradeDown();
        std::cout << bob << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    // 4) Boundary gradeUp / gradeDown errors
    std::cout << "\n-- gradeUp at grade = 1 → error --\n";
    try {
        Bureaucrat once("Once", 1);
        once.gradeUp();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "\n-- gradeDown at grade = 150 → error --\n";
    try {
        Bureaucrat last("Last", 150);
        last.gradeDown();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    // 5) Copy constructor
    std::cout << "\n-- Copy constructor --\n";
    {
        Bureaucrat orig("Original", 42);
        Bureaucrat copy(orig);
        std::cout << orig << "\n";
        std::cout << copy << "\n";
    }

    // 6) Assignment operator
    std::cout << "\n-- Assignment operator --\n";
    {
        Bureaucrat src("Source", 88);
        Bureaucrat dst("Dest", 100);
        std::cout << " before: dst = " << dst << "\n";
        dst = src;
        std::cout << " after : dst = " << dst << "\n";
    }

    return 0;
}



#include "baseABC.hpp"

int main() {
    // Seed random generator
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    for (int i = 1; i <= 10; ++i) {
        Base *p = generate();
        std::cout << "Instance " << i << ":\n";

        std::cout << "  identify(Base*): ";
        identify(p);

        std::cout << "  identify(Base&): ";
        identify(*p);

        delete p;
        std::cout << std::endl;
    }

    return 0;
}

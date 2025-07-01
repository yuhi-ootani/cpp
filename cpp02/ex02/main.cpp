
#include "Fixed.hpp"

int main() {
    std::cout << std::boolalpha; // print bools as true/false

    // ——— Construction ———
    Fixed a;       // default: 0
    Fixed b(5);    // from int
    Fixed c(2.5f); // from float
    Fixed d(b);    // copy ctor

    std::cout << "Initial values:\n";
    std::cout << " a = " << a << "\n";
    std::cout << " b = " << b << "\n";
    std::cout << " c = " << c << "\n";
    std::cout << " d = " << d << "  (copy of b)\n\n";

    // ——— Arithmetic ———
    std::cout << "Arithmetic:\n";
    std::cout << " b + c = " << (b + c) << "\n";
    std::cout << " b - c = " << (b - c) << "\n";
    std::cout << " b * c = " << (b * c) << "\n";
    std::cout << " b / c = " << (b / c) << "\n\n";

    // ——— Comparisons ———
    std::cout << "Comparisons (a vs b):\n";
    std::cout << " a >  b : " << (a > b) << "\n";
    std::cout << " a <  b : " << (a < b) << "\n";
    std::cout << " a >= d : " << (a >= d) << "\n";
    std::cout << " a <= d : " << (a <= d) << "\n";
    std::cout << " a == d : " << (a == d) << "\n";
    std::cout << " a != b : " << (a != b) << "\n\n";

    // ——— Increment / Decrement ———
    std::cout << "Increment / Decrement:\n";
    std::cout << " ++a  = " << ++a << "\n"; // prefix
    std::cout << " a    = " << a << "\n";
    std::cout << " a++  = " << a++ << "\n"; // postfix returns old
    std::cout << " a    = " << a << "\n\n";

    std::cout << " --b  = " << --b << "\n"; // prefix
    std::cout << " b    = " << b << "\n";
    std::cout << " b--  = " << b-- << "\n"; // postfix
    std::cout << " b    = " << b << "\n\n";

    // ——— min / max ———
    std::cout << "min/max (non-const):\n";
    std::cout << " min(a, c) = " << Fixed::min(a, c) << "\n";
    std::cout << " max(a, c) = " << Fixed::max(a, c) << "\n\n";

    const Fixed e(-1.25f);
    const Fixed f(3.75f);
    std::cout << "min/max (const):\n";
    std::cout << " min(e, f) = " << Fixed::min(e, f) << "\n";
    std::cout << " max(e, f) = " << Fixed::max(e, f) << "\n\n";

    return 0;
}
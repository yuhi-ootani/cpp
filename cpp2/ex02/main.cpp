
#include "Fixed.hpp"

int pdf_test() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    return 0;
}

int main() {
    pdf_test();
    std::cout << "====== pdf test fin ======\n\n";

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

    // ——— Comparisons ———
    std::cout << "Comparisons \n";
    std::cout << " a >  c : " << (a > c) << "\n";
    std::cout << " a <  c : " << (a < c) << "\n";
    std::cout << " a >= c : " << (a >= c) << "\n";
    std::cout << " a >= a : " << (a >= a) << "\n";
    std::cout << " a <= c : " << (a <= c) << "\n";
    std::cout << " a <= a : " << (a <= a) << "\n";
    std::cout << " a == c : " << (a == c) << "\n";
    std::cout << " a == a : " << (a == a) << "\n";
    std::cout << " a != c : " << (a != c) << "\n";
    std::cout << " a != a : " << (a != a) << "\n\n";

    // ——— Arithmetic ———
    std::cout << "Arithmetic:\n";
    std::cout << "b: float=" << b << " / raw=" << b.getRawBits() << "\n"
              << "c: float=" << c << " / raw=" << c.getRawBits() << "\n\n";
    std::cout << " b + c = " << (b + c) << " raw=" << (b + c).getRawBits() << "\n";
    std::cout << " b - c = " << (b - c) << " raw=" << (b - c).getRawBits() << "\n";
    std::cout << " b * c = " << (b * c) << " raw=" << (b * c).getRawBits() << "\n";
    std::cout << " b / c = " << (b / c) << " raw=" << (b / c).getRawBits() << "\n\n";

    // ——— Increment / Decrement ———
    std::cout << "Increment / Decrement:\n";
    std::cout << " ++a  = " << (++a).getRawBits() << "\n"; // prefix
    std::cout << " a    = " << a.getRawBits() << "\n";
    std::cout << " a++  = " << (a++).getRawBits() << "\n"; // postfix returns old
    std::cout << " a    = " << a.getRawBits() << "\n\n";

    std::cout << " --b  = " << (--b).getRawBits() << "\n"; // prefix
    std::cout << " b    = " << b.getRawBits() << "\n";
    std::cout << " b--  = " << (b--).getRawBits() << "\n"; // postfix
    std::cout << " b    = " << b.getRawBits() << "\n\n";

    // ——— min / max ———
    Fixed &mn1 = Fixed::min(a, c);
    Fixed &mx1 = Fixed::max(a, c);
    std::cout << " min(a, c) = " << mn1 << " (raw=" << mn1.getRawBits() << ")\n";
    std::cout << " max(a, c) = " << mx1 << " (raw=" << mx1.getRawBits() << ")\n\n";

    const Fixed e(-1.25f);
    const Fixed f(3.75f);
    std::cout << "min/max (const):\n";
    const Fixed &mn2 = Fixed::min(e, f);
    const Fixed &mx2 = Fixed::max(e, f);
    std::cout << " min(e, f) = " << mn2 << " (raw=" << mn2.getRawBits() << ")\n";
    std::cout << " max(e, f) = " << mx2 << " (raw=" << mx2.getRawBits() << ")\n";

    return 0;
}

#include "whatever.hpp"

int main(void) {
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    int sameA = 3;
    int sameB = 3;
    ::swap(sameA, sameB);
    std::cout << "sameA = " << &sameA << ", sameB = " << &sameB << std::endl;
    std::cout << "min( a, b ) = " << &(::min(sameA, sameB)) << std::endl;
    std::cout << "max( a, b ) = " << &(::max(sameA, sameB)) << std::endl;

    return 0;
}

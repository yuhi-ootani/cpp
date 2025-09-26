
#include "iter.hpp"

int main() {
    int intArr[] = {0, 1, 2, 3, 4};
    std::cout << "=== Non-Const Array * Non-const func ===\n";
    iter(intArr, 5, print_double<int>);

    const std::string strArr[] = {"hello", "world", "iter", "test", "banana"};
    std::cout << "\n=== Const Array * Const Array ===\n";
    iter(strArr, 4, &print_const<const std::string>);

    std::cout << "\n=== Non-Const Array * Const Array ===\n";
    iter(intArr, 5, &print_const);

    std::cout << "\n=== Non-Const Array * Const Array ===\n";
    iter(strArr, 5, &print);
    return 0;
}

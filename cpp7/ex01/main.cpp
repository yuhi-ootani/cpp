
#include "iter.hpp"

int main() {
    // 1) non-const int array
    int intArr[] = {0, 1, 2, 3, 4};
    std::cout << "=== intArr ===\n";
    iter(intArr, 5, printElem);

    // 2) const std::string array
    const std::string strArr[] = {"hello", "world", "iter", "test"};
    std::cout << "\n=== const std::string array ===\n";
    iter(strArr, 4, &printElem_const<const std::string>);

    return 0;
}

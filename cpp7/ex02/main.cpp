

#include "Array.hpp"

int main(void) {
    int *a = new int();
    std::cout << "\n === a is " << *a << " ===\n";

    std::cout << "\n === empty array === \n";
    Array<int> empty;
    try {
        std::cout << "empty.size() == " << empty.size() << "\n";
        std::cout << "empty[0] == " << empty[0] << "\n";
    } catch (std::exception &e) {
        std::cerr << "empty array error :" << e.what() << std::endl;
    }

    std::cout << "\n === argument array === \n";
    Array<int> arr(3);
    arr[2] = 42;
    try {
        std::cout << arr[0] << "\n";
        std::cout << arr[1] << "\n";
        std::cout << arr[2] << "\n";
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n === copy array & const array === \n";
    const Array<int> copy(arr);
    std::cout << "=== deep copy: change the original array (arr[0] = 43) === \n";
    arr[0] = 43;
    // error
    // copy[0] = 55;
    // copy = arr;

    try {
        std::cout << copy[0] << "\n";
        std::cout << copy[1] << "\n";
        std::cout << copy[2] << "\n";
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n === assignment array and out of range === \n";
    empty = arr;
    try {
        std::cout << empty[0] << "\n";
        std::cout << empty[1] << "\n";
        std::cout << empty[2] << "\n";
        std::cout << empty[3] << "\n";
    } catch (std::out_of_range &e) {
        std::cerr << "ERROR:" << e.what() << std::endl;
    }

    std::cout << "\n === string array and size member function === \n";
    Array<std::string> string_arr(2);
    string_arr[0] = "HELLOOOOOO";
    try {
        std::cout << string_arr[0] << "\n";
        std::cout << string_arr[1] << "\n";
        std::cout << "string arr size is " << string_arr.size() << "\n";
    } catch (std::out_of_range &e) {
        std::cerr << "ERROR:" << e.what() << std::endl;
    }

    return 0;
}

// main.cpp
#include "easyfind.hpp"
#include <cassert>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
    int tmp[] = {1, 6, 4, 6, 0, 1, 4, 3, 0, 5, 7, 8};
    const std::size_t N = sizeof(tmp) / sizeof(tmp[0]);
    {
        std::cout << "\n ──  vector (success)\n";
        std::vector<int> v(tmp, tmp + N);
        std::vector<int>::const_iterator iter1 = easyfind(v, 4);

        std::vector<int>::const_iterator first = v.begin();
        // std::vector<int>::difference_type idx = std::distance(first, iter);

        std::cout << "Vector: Target is " << *iter1 << " Index number is "
                  << std::distance(first, iter1) << "\n";

        std::cout << "\n ──  vector (fail)\n";
        try {
            std::vector<int>::const_iterator iter2 = easyfind(v, 42);
            std::cout << "Target is " << *iter2 << "\n";
        } catch (std::out_of_range &e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    {
        std::cout << "\n ──  list (success)\n";
        std::list<int> v(tmp, tmp + N);
        std::list<int>::const_iterator iter1 = easyfind(v, 6);

        std::list<int>::const_iterator first = v.begin();

        std::cout << "Target is " << *iter1 << " Index number is " << std::distance(first, iter1)
                  << "\n";

        std::cout << "\n ──  list (fail)\n";
        try {
            std::list<int>::const_iterator iter2 = easyfind(v, 42);
            std::cout << "List: Target is " << *iter2 << "\n";
        } catch (std::out_of_range &e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    {
        std::cout << "\n ──  non-const deque (success)\n";
        std::deque<int> v(tmp, tmp + N);
        std::deque<int>::iterator iter1 = easyfind(v, 0);

        std::deque<int>::difference_type index = iter1 - v.begin();
        std::cout << "Target is " << *iter1 << " Index number is " << index << "\n";

        std::cout << "\n ──  non-const deque (fail)\n";
        try {
            std::deque<int>::const_iterator iter2 = easyfind(v, 42);
            std::cout << "Deque: Target is " << *iter2 << "\n";
        } catch (std::out_of_range &e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    // ==== DIFFERENT TYPE ========
    // std::vector<std::string> v_str;
    // std::vector<std::string>::const_iterator iter_str = easyfind(v_str, 4);

    return 0;
}

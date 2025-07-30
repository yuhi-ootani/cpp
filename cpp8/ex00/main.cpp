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
        // ──  vector (success)
        std::vector<int> v(tmp, tmp + N);
        std::vector<int>::const_iterator iter = easyfind(v, 4);

        // difference_type: the type used to say “how many steps” separate two iterators.
        std::vector<int>::difference_type idx = iter - v.begin();
        std::cout << "Vector: Target is " << *iter << " Idex number is " << idx << "\n";

        // ──  vector (fail)
        try {
            std::vector<int>::const_iterator iter2 = easyfind(v, 42);
            std::cout << "Target is " << *iter2 << "\n";
        } catch (std::out_of_range &e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    {
        // ──  list (success)
        std::list<int> v(tmp, tmp + N);
        std::list<int>::const_iterator iter1 = easyfind(v, 6);

        std::list<int>::const_iterator first = v.begin();
        std::list<int>::difference_type idx = std::distance(first, iter1);

        std::cout << "Target is " << *iter1 << " Idex number is " << idx << "\n";

        // ──  list (fail)
        try {
            std::list<int>::const_iterator iter2 = easyfind(v, 42);
            std::cout << "List: Target is " << *iter2 << "\n";
        } catch (std::out_of_range &e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    {
        // ──  deque (success)
        std::deque<int> v(tmp, tmp + N);
        std::deque<int>::const_iterator iter1 = easyfind(v, 0);

        std::deque<int>::difference_type idx = iter1 - v.begin();
        std::cout << "Target is " << *iter1 << " Idex number is " << idx << "\n";

        // ──  deque (fail)
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

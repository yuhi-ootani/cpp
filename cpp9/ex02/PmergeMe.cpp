
#include "PmergeMe.hpp"

long jacobsthal_number(long n) {
    if (n <= 0)
        return 0; // J0 = 0
    if (n == 1)
        return 1; // J1 = 1
    long a = 0;   // J0
    long b = 1;   // J1
    for (long i = 2; i <= n; ++i) {
        long c = b + 2 * a; // Jn = J(n-1) + 2*J(n-2)
        a = b;
        b = c;
    }
    return b;
}

PmergeMe::PmergeMe() : _vec(), _deque() {}

PmergeMe::PmergeMe(const std::vector<int> &before)
    : _vec(before), _deque(before.begin(), before.end()) {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _vec = other._vec;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVec() { size_t block_size = biggest_block_sort(_vec); }

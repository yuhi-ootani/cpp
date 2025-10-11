
#include "PmergeMe.hpp"

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



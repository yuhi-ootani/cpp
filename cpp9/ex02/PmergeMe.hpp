
#ifndef PMERGEME
#define PMERGEME

#include <cerrno>
#include <climits>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <set>
#include <string>
#include <vector>

class PmergeMe {
  private:
    std::vector<int> _vec;
    std::deque<int> _deque;

  public:
    PmergeMe();
    PmergeMe(const std::vector<int> &before);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sortVec();
    void sortDeque();
};

#endif

template <typename Container>

// L 1 2 M 4 5 R;
static inline void swap_bigger_block(Container &c, size_t L, size_t M, size_t R) {
    if (c[R - 1] < c[M - 1])
        std::rotate(c.begin() + L, c.begin() + M, c.begin() + R);
}

template <typename Container>

static inline size_t biggest_block_sort(Container &c) {
    const size_t elements = c.size();
    if (elements < 2)
        return 1;

    size_t block_size = 1;
    for (; (block_size << 1) <= elements; block_size *= 2) {
        size_t full_blocks = elements / block_size;
        const size_t end_block = (full_blocks & 1) ? full_blocks - 1 : full_blocks;

        for (size_t cur_block = 0; cur_block + 1 < end_block; cur_block += 2) {
            size_t L = cur_block * block_size;
            size_t M = L + block_size;
            size_t R = M + block_size;
            swap_bigger_block(c, L, M, R);
        }
    }
    return block_size;
}

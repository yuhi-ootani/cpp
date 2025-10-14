
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

// static inline std::vector<int>::iterator block_head(std::vector<int>::iterator begin,
//                                                     size_t block_size, size_t ui) {
//     return begin + ui * block_size - 1;
// }

static inline void split_main_pend(std::vector<int> &container, std::vector<vec_iter> &main,
                                   std::vector<vec_iter> &pend, const t_block &bl) {

    main.clear();
    pend.clear();

    if (bl.each_size <= 0 || bl.total_nbr < 2)
        return;

    const std::vector<int>::iterator begin = container.begin();

    main.reserve(bl.total_nbr);
    pend.reserve(bl.total_nbr / 2 + (bl.is_odd ? 1 : 0));

    main.push_back(begin + (1 * bl.each_size) - 1); // loser1 (b1)
    main.push_back(begin + (2 * bl.each_size) - 1); // winner1 (a1)

    for (size_t i = 3; i + 1 <= bl.total_nbr; i += 2) {
        pend.push_back(begin + (i * bl.each_size - 1));
        main.push_back(begin + ((i + 1) * bl.each_size - 1));
    }

    if (bl.is_odd) {
        pend.push_back(begin + (bl.total_nbr * bl.each_size - 1));
    }
}

static void swap_container_vector(std::vector<int> &vec, const std::vector<vec_iter> &main,
                                  int block_size) {
    if (main.empty() || block_size <= 0)
        return;

    const size_t total = main.size() * block_size;
    std::vector<int> tmp(total); // diff

    size_t tmp_i = 0;
    for (std::vector<vec_iter>::const_iterator it = main.begin(); it != main.end(); ++it) {
        vec_iter head = *it;
        vec_iter start = head - (block_size - 1);

        std::memcpy(&tmp[tmp_i], &*start, block_size * sizeof(int)); // diff
        tmp_i += block_size;
    }

    std::memcpy(&vec[0], &tmp[0], total * sizeof(int)); // diff
}

void PmergeMe::sortVec() {
    size_t block_size = biggest_block_sort(_vec);

    std::vector<vec_iter> main;
    std::vector<vec_iter> pend;
    for (; block_size >= 1; block_size /= 2) {
        t_block block;
        get_block_info(block_size, block, _vec);
        split_main_pend(_vec, main, pend, block);
        merge_insertion(main, pend, block);
        swap_container_vector(_vec, main, block_size);
    }
}

static void swap_container_deque(std::deque<int> &deque, const std::deque<deq_iter> &main,
                                 int block_size) {
    if (main.empty() || block_size <= 0)
        return;

    const size_t total = main.size() * block_size;
    std::deque<int> tmp;
    tmp.resize(total); // diff

    size_t tmp_i = 0;
    deq_iter tmp_it = tmp.begin();
    for (std::deque<deq_iter>::const_iterator it = main.begin(); it != main.end(); ++it) {
        deq_iter head = *it;
        deq_iter start = head - (block_size - 1);

        std::copy(start, start + block_size, tmp.begin() + tmp_i); // diff
        tmp_i += block_size;
    }

    std::copy(tmp.begin(), tmp.end(), deque.begin()); // diff
}

const std::vector<int> &PmergeMe::getVec() const { return _vec; }
const std::deque<int> &PmergeMe::getDeque() const { return _deque; }

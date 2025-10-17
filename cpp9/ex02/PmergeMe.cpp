
#include "PmergeMe.hpp"

//////////////////////////////////////
////////// Helper Functions //////////
//////////////////////////////////////

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

//////////////////////////////////////////////
////////// Orthodox Canonical class //////////
//////////////////////////////////////////////

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

//////////////////////////////////////////////
/////////// vector sort function /////////////
//////////////////////////////////////////////

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
    // global_count = 0;
    size_t block_size = biggest_block_sort(_vec);

    std::vector<vec_iter> main;
    std::vector<vec_iter> pend;
    for (; block_size >= 1; block_size /= 2) {
        t_block block;
        setup_block(block_size, block, _vec, main, pend);

        main.reserve(block.total_nbr);
        pend.reserve(block.total_nbr / 2 + (block.is_odd ? 1 : 0));

        split_main_pend(_vec, main, pend, block);
        merge_insertion(main, pend, block);
        swap_container_vector(_vec, main, block_size);
    }
    // std::cout << "Vector Comparision times : " << global_count << "\n";
}

//////////////////////////////////////////////
/////////// deque sort function //////////////
//////////////////////////////////////////////

static void swap_container_deque(std::deque<int> &deque, const std::deque<deq_iter> &main,
                                 int block_size) {
    if (main.empty() || block_size <= 0)
        return;

    const size_t total = main.size() * block_size;
    std::deque<int> tmp;
    tmp.resize(total); // diff

    size_t tmp_i = 0;
    for (std::deque<deq_iter>::const_iterator it = main.begin(); it != main.end(); ++it) {
        deq_iter head = *it;
        deq_iter start = head - (block_size - 1);

        std::copy(start, start + block_size, tmp.begin() + tmp_i); // diff
        tmp_i += block_size;
    }

    std::copy(tmp.begin(), tmp.end(), deque.begin()); // diff
}

void PmergeMe::sortDeque() {
    // global_count = 0;
    size_t block_size = biggest_block_sort(_deque);

    std::deque<deq_iter> main;
    std::deque<deq_iter> pend;
    for (; block_size >= 1; block_size /= 2) {
        t_block block;
        setup_block(block_size, block, _deque, main, pend);
        split_main_pend(_deque, main, pend, block);
        merge_insertion(main, pend, block);
        swap_container_deque(_deque, main, block_size);
    }
    // std::cout << "Deque  Comparision times : " << global_count << "\n";
}

///////////////////////////////////////////
///////// Getter functions ////////////////
///////////////////////////////////////////

const std::vector<int> &PmergeMe::getVec() const { return _vec; }
const std::deque<int> &PmergeMe::getDeque() const { return _deque; }

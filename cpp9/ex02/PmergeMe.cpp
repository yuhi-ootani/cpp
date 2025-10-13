
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

static inline void 

static inline void split_main_pend(std::vector<int> &container, size_t block_size,
                                   std::vector<vec_iter> &main, std::vector<vec_iter> &pend) {

    main.clear();
    pend.clear();

    if (block_size == 0)
        return;

    const size_t blocks_nbr = container.size() / block_size;
    if (blocks_nbr < 2)
        return;

    const bool is_odd = (blocks_nbr & 1);

    const std::vector<int>::iterator begin = container.begin();

    main.reserve(blocks_nbr);
    pend.reserve(blocks_nbr / 2 + (is_odd ? 1 : 0));

    main.push_back(begin + (1 * block_size) - 1); // loser1 (b1)
    main.push_back(begin + (2 * block_size) - 1); // winner1 (a1)

    for (size_t i = 3; i + 1 <= blocks_nbr; i += 2) {
        pend.push_back(begin + (i * block_size - 1));
        main.push_back(begin + ((i + 1) * block_size - 1));
    }

    if (is_odd) {
        pend.push_back(begin + (blocks_nbr * block_size - 1));
    }
}

static void merge_insertion(std::vector<vec_iter> &main, std::vector<vec_iter> &pend) {

    int pre_j = jacobsthal_number(1);
    int inserted_nbr = 0;
    int seed_j = 2;

    while (!pend.empty()) {

        const int cur_j = jacobsthal_number(seed_j);
        int diff_j = cur_j - pre_j;
        if (diff_j <= 0) {
            ++seed_j;
            pre_j = cur_j;
            continue;
        }

        int pend_size = static_cast<int>(pend.size());
        int insert_times = (diff_j < pend_size) ? diff_j : pend_size;
        bool remain_round = (insert_times < diff_j);
        int fence_changed = 0;

        for (int pend_i = insert_times - 1; pend_i >= 0; --pend_i) {
            std::vector<int>::iterator pend_value = pend[pend_i];

            int right_fence_index;
            if (!remain_round)
                right_fence_index = cur_j + inserted_nbr - fence_changed;
            else
                right_fence_index = static_cast<int>(main.size()) - static_cast<int>(pend.size()) +
                                    pend_i + (is_odd ? 1 : 0);

            if (right_fence_index > static_cast<int>(main.size()))
                right_fence_index = static_cast<int>(main.size());

            std::vector<vec_iter>::iterator right_fence_iter = main.begin() + right_fence_index;

            std::vector<vec_iter>::iterator insert_pos =
                std::upper_bound(main.begin(), right_fence_iter, pend_value, comp_iter<vec_iter>);

            std::vector<vec_iter>::iterator inserted_iter = main.insert(insert_pos, pend_value);

            if (insert_pos == right_fence_iter) {
                ++fence_changed;
            }
        }

        pend.erase(pend.begin(), pend.begin() + insert_times);

        if (!remain_round) {
            pre_j = cur_j;
            inserted_nbr += insert_times;
            ++seed_j;
        }
    }
}

void PmergeMe::sortVec() {
    size_t block_size = biggest_block_sort(_vec);
    std::vector<vec_iter> main;
    std::vector<vec_iter> pend;

    for (; block_size > 1; block_size /= 2) {
        split_main_pend(_vec, block_size, main, pend);
        merge_insertion(main, pend);
        swap_container(_vec, main);
    }
}

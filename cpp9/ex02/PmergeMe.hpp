
#ifndef PMERGEME
#define PMERGEME

#include <algorithm>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <set>
#include <string>
#include <vector>

typedef std::vector<int>::iterator vec_iter;
typedef std::deque<int>::iterator deq_iter;

typedef struct s_block {
    size_t each_size;
    size_t total_nbr;
    bool is_odd;
} t_block;

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
    const std::vector<int> &getVec() const;
    const std::deque<int> &getDeque() const;
};

long jacobsthal_number(long n);

template <typename Container, typename Holder>
static inline void setup_block(size_t block_size, t_block &block, const Container &container,
                               Holder &main, Holder &pend) {

    block.each_size = block_size;
    block.total_nbr = container.size() / block_size;
    block.is_odd = (block.total_nbr & 1) != 0;
    main.clear();
    pend.clear();
}

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
        size_t blocks_nbr = elements / block_size;
        const size_t end_block = (blocks_nbr & 1) ? blocks_nbr - 1 : blocks_nbr;

        for (size_t cur_block = 0; cur_block + 1 < end_block; cur_block += 2) {
            size_t L = cur_block * block_size;
            size_t M = L + block_size;
            size_t R = M + block_size;
            swap_bigger_block(c, L, M, R);
        }
    }
    return block_size;
}

template <typename Container, typename Holder>
static inline void split_main_pend(Container &container, Holder &main, Holder &pend,
                                   const t_block &bl) {

    if (bl.each_size <= 0 || bl.total_nbr < 2)
        return;

    typename Container::iterator begin = container.begin();

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

template <typename Iter>

bool comp_iter(Iter a, Iter b) {
    return *a < *b;
}

template <typename Holder>

static void merge_insertion(Holder &main, Holder &pend, const t_block &block) {

    typedef typename Holder::value_type DataIter; // container's data type
    typedef typename Holder::iterator HolderIter; // holder's iterator

    int pre_j = jacobsthal_number(2);
    int inserted_nbr = 0;

    for (int seed_j = 3; !pend.empty(); ++seed_j) {

        const int cur_j = jacobsthal_number(seed_j);
        const int diff_j = cur_j - pre_j;
        int insert_times = std::min(diff_j, static_cast<int>(pend.size()));
        int fence_changed = 0;

        for (int pend_i = insert_times - 1; pend_i >= 0; --pend_i) {
            DataIter pend_value = pend[pend_i];

            int fence_index;

            int main_size = static_cast<int>(main.size());
            if (insert_times == diff_j)
                fence_index = cur_j + inserted_nbr - fence_changed;
            else
                fence_index =
                    main_size - static_cast<int>(pend.size()) + pend_i + (block.is_odd ? 1 : 0);

            if (fence_index > main_size)
                fence_index = main_size;

            HolderIter fence_iter = main.begin() + fence_index;

            HolderIter insert_pos =
                std::upper_bound(main.begin(), fence_iter, pend_value, comp_iter<DataIter>);

            HolderIter inserted_iter = main.insert(insert_pos, pend_value);

            const int inserted_idx = static_cast<int>(inserted_iter - main.begin());
            if (inserted_idx == fence_index) {
                ++fence_changed;
            }
        }

        pend.erase(pend.begin(), pend.begin() + insert_times);
        pre_j = cur_j;
        inserted_nbr += insert_times;
    }
}

template <typename Container>

void print_container(const Container &c) {
    std::cout << "After: ";

    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

#endif

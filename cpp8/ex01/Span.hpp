
#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <vector>

class Span {
  private:
    unsigned int _limit;
    std::vector<int> _v;

    struct Iota {
        int cur;
        Iota(int start) : cur(start) {}
        int operator()() { return cur++; }
    };

  public:
    Span();
    Span(const Span &other);
    Span(unsigned long N);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int value);
    void addNumber(int from, int to);

    unsigned int shortestSpan();
    unsigned int longestSpan();
    void printVector();

    template <typename Iter>

    void addNumber(Iter first, Iter last);
};

template <typename Iter>

void Span::addNumber(Iter first, Iter last) {
    unsigned int cnt = static_cast<unsigned int>(std::distance(first, last));
    if (_v.size() + cnt > _limit)
        throw std::out_of_range("too many elements!!");
    _v.insert(_v.end(), first, last);
}

#endif

// < WHY VECTOR >
/*
 * Advantages of std::vector<int> for Span:
 *  - Contiguous storage: excellent cache locality and minimal per-element overhead.
 *  - Random-access iterators: constant-time indexing, pointer arithmetic, and std::minmax_element.
 *  - Amortized O(1) insertion (with reserve): fast addNumber() up until capacity.
 *  - Simple algorithms: sort once (O(N log N)) + single linear scan (O(N)) to compute
 * shortestSpan().
 *
 * Disadvantages of std::list<int> for Span:
 *  - No random-access iterators: cannot use operator- or constant-time indexing; need
 * std::distance().
 *  - Poor cache performance: pointer-chasing on every traversal.
 *  - Higher memory overhead: each node carries extra pointers + allocation metadata.
 *  - More complex code: list::sort() is merge-sort with less efficient memory access; adjacent
 * scanning still O(N).
 */

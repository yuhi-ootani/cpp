
#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

class Span {
  private:
    unsigned int _limit;
    std::vector<int> _v;

  public:
    Span();
    Span(const Span &other);
    Span(unsigned long N);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int value);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    void printVector();
    void addNumber(int first, int last);
    // template <typename InputIt> void addNumber(InputIt first, InputIt last);
};

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

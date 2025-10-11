
#ifndef PMERGEME
#define PMERGEME

#include <deque>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cstdlib>
#include <cerrno>
#include <climits>

class PmergeMe {
  private:
   
    std::vector<int> _vec;
    std::deque<int> _deque;

  public:
    PmergeMe();
    PmergeMe(const std::vector<int>& before);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();
};

#endif

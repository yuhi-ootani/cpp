
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

// default underlying container of stack is deque
template <typename T, typename Container = std::deque<T>

          >

class MutantStack : public std::stack<T, Container> {
  public:
    MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack &operator=(const MutantStack &other);
    ~MutantStack();

    typedef std::stack::deque::iterator iterator;
}

#endif

#include "MutantStack.hpp"

<<<<<<< HEAD
template <typename T1, typename C1, typename T2, typename C2>

void subject_test(MutantStack<T1, C1> &mstack, MutantStack<T2, C2> &sstack) {
    std::cout << "subject test" << std::endl;
=======
int main() {
    MutantStack<int> mstack;
>>>>>>> f50f495 (adfa)
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
<<<<<<< HEAD
    mstack.push(0);

    typename MutantStack<T1, C1>::iterator it = mstack.begin();
    typename MutantStack<T1, C1>::const_iterator ite = mstack.end();
    ++it;
    --it;
    *it = *it * 2;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<T1, C1> s(mstack);

    std::cout << "\nstring stack" << std::endl;
    sstack.push("a");
    sstack.push("b");
    sstack.push("c");
    sstack.push("pop");
    sstack.pop();

    typename MutantStack<T2, C2>::reverse_iterator rit = sstack.rbegin();
    typename MutantStack<T2, C2>::const_reverse_iterator rite = sstack.rend();

    std::cout << "reverser iterator" << std::endl;
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }
}

void list_test() {
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
=======
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
>>>>>>> f50f495 (adfa)
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
<<<<<<< HEAD
    std::stack<int, std::list<int>

               >
        s(mstack);
}

int main() {
    // ----- default underlying container (std::deque<T>) -----
    MutantStack<int> mstack_deque;
    MutantStack<std::string> sstack_deque;
    std::cout << "===== default underlying container (deque) =====\n";
    subject_test(mstack_deque, sstack_deque);

    MutantStack<int, std::list<int>

                >
        mstack_list;

    MutantStack<std::string, std::list<std::string>

                >
        sstack_list;
    std::cout << "\n===== underlying container = std::list =====\n";
    subject_test(mstack_list, sstack_list);

    MutantStack<int, std::vector<int>

                >
        mstack_vector;

    MutantStack<std::string, std::vector<std::string>

                >
        sstack_vector;
    std::cout << "\n===== underlying container = std::vector =====\n";
    subject_test(mstack_vector, sstack_vector);

    std::cout << "\n=====list test =====\n";
    list_test();
    return 0;
}
=======
    std::stack<int> s(mstack);
    return 0;
}
>>>>>>> f50f495 (adfa)

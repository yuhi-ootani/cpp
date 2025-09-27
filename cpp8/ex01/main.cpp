
#include "Span.hpp"

int main() {
    std::cout << "\n === subject test === \n";
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        sp.printVector();
        std::cout << "shortest " << sp.shortestSpan() << std::endl;
        std::cout << "longest " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n === range of iterators test === \n";
    {
        Span sp = Span(4294967295);
        try {
            sp.addNumber(static_cast<int>(-100), 0);
            std::cout << "shortest " << sp.shortestSpan() << std::endl;
            std::cout << "longest " << sp.longestSpan() << std::endl;
            sp.printVector();
        } catch (std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }

    std::cout << "\n === itelator range test === \n";
    {
        std::vector<int> src;
        src.reserve(100002);
        for (int i = 1; i <= 10000; ++i)
            src.push_back(i);
        src.push_back(INT_MIN);
        src.push_back(INT_MAX);

        Span sp(src.size());
        sp.addNumber(src.begin(), src.end());

        std::cout << "shortest " << sp.shortestSpan() << std::endl;
        std::cout << "longest " << sp.longestSpan() << std::endl;

        std::cout << "\n === too many elements test === \n";
        try {
            sp.addNumber(0);
        } catch (std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }

    std::cout << "\n === constructor error === \n";
    {
        try {
            Span sp(static_cast<unsigned long>(std::numeric_limits<unsigned int>::max()) + 1UL);
        } catch (std::exception &e) {
            std::cout << e.what() << '\n';
        }
        try {
            Span sp = Span(-1);
        } catch (std::exception &e) {
            std::cout << e.what() << '\n';
        }
    }

    return 0;
}


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
        Span sp = Span(1000000);
        sp.addNumber(1, 100000);
        std::cout << "shortest " << sp.shortestSpan() << std::endl;
        std::cout << "longest " << sp.longestSpan() << std::endl;
        sp.printVector();
        try {
            sp.addNumber(0);
        } catch (std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }

    std::cout << "\n === constructor error === \n";
    {
        try {
            Span sp =
                Span(static_cast<unsigned long>(std::numeric_limits<unsigned int>::max()) + 1UL);
        } catch (std::exception &e) {
            std::cout << e.what() << '\n';
        }
        try {
            Span sp = Span(-134298798);
        } catch (std::exception &e) {
            std::cout << e.what() << '\n';
        }
    }

    return 0;
}

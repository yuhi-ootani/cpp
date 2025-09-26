

#include "Span.hpp"

Span::Span() : _limit(0), _v() {
    _v.reserve(10000);
    std::cout << "default constructor called\n";
}

Span::Span(unsigned long N) : _limit(N), _v() {
    if (N < 0 || N > static_cast<unsigned long>(std::numeric_limits<unsigned int>::max()))
        throw std::out_of_range("Span size out of valid range!!");
    _v.reserve(_limit);
    std::cout << "argument constructor called\n";
}

Span::Span(const Span &other) : _limit(other._limit), _v(other._v) {
    std::cout << "copy constructor called\n";
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _limit = other._limit;
        _v = other._v;
    }
    return *this;
}

Span::~Span() { std::cout << "destructor called\n"; }

void Span::addNumber(int value) {
    if (_v.size() >= _limit) {
        throw std::out_of_range("container is full!!");
    }
    _v.push_back(value);
}

void Span::addNumber(int from, int to) {
    if (from > to)
        std::swap(from, to);

    unsigned int count = to - from + 1;

    if (_v.size() + count > _limit)
        throw std::out_of_range("too many elements!!");

    _v.reserve(_v.size() + count);
    Iota gen(from);
    std::generate_n(std::back_inserter(_v), count, gen);
}

unsigned int Span::shortestSpan() {
    if (_v.size() <= 1) {
        throw std::length_error("too short span!!1");
    }
    std::vector<int> tmp(_v.begin(), _v.end());
    std::sort(tmp.begin(), tmp.end());

    unsigned int min = tmp[1] - tmp[0];
    unsigned int diff;

    for (unsigned int i = 2, end = tmp.size(); i < end; i++) {
        diff = tmp[i] - tmp[i - 1];
        if (diff < min)
            min = diff;
    }
    return min;
}

unsigned int Span::longestSpan() {

    if (_v.size() <= 1) {
        throw std::length_error("too short span!!");
    }

    std::vector<int> tmp(_v.begin(), _v.end());
    unsigned int max;
    std::sort(tmp.begin(), tmp.end());
    max = static_cast<unsigned int>(tmp[tmp.size() - 1] - tmp[0]);
    return max;
}

void Span::printVector() {
    for (unsigned int i = 0, end = _v.size(); i < end; i++) {
        std::cout << _v[i] << ", ";
        if ((i + 1) % 10 == 0)
            std::cout << "\n";
    }
    std::cout << std::endl;
}

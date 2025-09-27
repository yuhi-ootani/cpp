

#include "Span.hpp"

Span::Span() : _limit(2), _v() {
    _v.reserve(2);
    std::cout << "default constructor called\n";
}

Span::Span(unsigned long N) : _limit(0), _v() {
    const unsigned long UMAX = std::numeric_limits<unsigned int>::max();
    if (N < 2 || N > UMAX)
        throw std::out_of_range("Span size out of valid range!!");
    _limit = static_cast<unsigned int>(N);
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

    unsigned int ufrom = static_cast<unsigned int>(from);
    unsigned int uto = static_cast<unsigned int>(to);
    unsigned int count = uto - ufrom;

    if (count == std::numeric_limits<unsigned>::max())
        throw std::out_of_range("range too large");

    ++count;

    if (count > _limit - static_cast<unsigned int>(_v.size()))
        throw std::out_of_range("too many elements!!");

    _v.reserve(_v.size() + count);
    Iota gen(from);
    std::generate_n(std::back_inserter(_v), count, gen);
}

unsigned int Span::shortestSpan() const {
    if (_v.size() < 2) {
        throw std::length_error("too short span!!");
    }
    std::vector<int> tmp(_v.begin(), _v.end());
    std::sort(tmp.begin(), tmp.end());

    unsigned int min = std::numeric_limits<unsigned int>::max();
    unsigned int diff;
    for (unsigned int i = 1; i < tmp.size(); ++i) {
        diff = static_cast<unsigned int>(tmp[i]) - static_cast<unsigned int>(tmp[i - 1]);
        if (diff < min) {
            min = diff;
        }
    }

    return min;
}

unsigned int Span::longestSpan() const {

    if (_v.size() < 2) {
        throw std::length_error("too short span!!");
    }

    int low = *std::min_element(_v.begin(), _v.end());
    int high = *std::max_element(_v.begin(), _v.end());

    return static_cast<unsigned int>(high) - static_cast<unsigned int>(low);
}

void Span::printVector() const {
    std::size_t i = 0;
    for (std::vector<int>::const_iterator it = _v.begin(); it != _v.end(); ++it, ++i) {
        std::cout << *it;
        if (i + 1 < _v.size())
            std::cout << ", ";
        if ((i + 1) % 10 == 0)
            std::cout << "\n";
    }
    std::cout << '\n';
}


#include "Array.hpp"

template <typename T>

Array<T>::Array() : _size(0), _array(new T[0]) {
    std::cout << "default constructor called\n";
}

template <typename T>

Array<T>::Array(unsigned int n) : _size(n), array(new T[n]) {
    std::cout << "constructor called\n";
}

template <typename T>

Array<T>::Array(const Array &other) {
    std::cout << "copy constructor called\n";
    *this = other;
}

template <typename T>

Array<T> &Array<T>::operator=(const Array<T> &other) {
    if (this != &other) {
        delete _array;
        _array = other.array;
        _size = other.size
    }
    return *this;
}

template <typename T>

Array<T>::~Array() {
    std::cout << "destructor called\n";
    delete _array;
}

template <typename T>

unsigned int Array<T>::size() const {
    return _size();
}

template <typename T>

T &Array<T>::operator[](unsigned int idx) {
    if (unsigned int idx >= _size)
        throw std::out_of_range("Index out of range");
    return _array[idx];
}

#include "Array.hpp"

// Every function you write outside the class needs to begin with its own template declaration.
// Without it, the compiler would think you’re defining a normal (non‑template) function:
template <typename T>

// Array<T>
// No <T> on Array → the compiler won’t connect your definition to the Array template.
// because Array by itself isn’t a concrete type
Array<T>::Array() : _size(0), _array(new T[0]()) {
    std::cout << "default constructor called\n";
}

template <typename T> Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]()) {
    std::cout << "constructor called\n";
}

template <typename T>
Array<T>::Array(const Array &other) : _size(other.size()), _array(new T[_size]) {
    std::cout << "copy constructor called\n";
    for (unsigned int i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &other) {
    if (this != &other) {
        _size = other._size;
        delete[] _array;
        _array = new T[other._size];
        for (unsigned int i = 0; i < _size; i++) {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

template <typename T> Array<T>::~Array() {
    std::cout << "destructor called\n";
    delete[] _array;
}

template <typename T> unsigned int Array<T>::size() const { return _size; }

// std::out_of_range
// if you use it, you can catch the specific exeception!
template <typename T> T &Array<T>::operator[](unsigned int idx) {
    if (idx >= _size)
        throw std::out_of_range("Index out of range");
    return _array[idx];
}

template <typename T> const T &Array<T>::operator[](unsigned int idx) const {
    if (idx >= _size)
        throw std::out_of_range("Index out of range");
    return _array[idx];
}


#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <typeinfo>

// void iter(T* array, std::size_t length, T func);
// – You can’t pass a function template name to a parameter of type T, so template argument
// deduction fails.

// void iter(T* array, std::size_t length, void (*f)(const T&))
// – Function‐to‐pointer conversion:
// a bare function name or function reference will automatically decay to a pointer.
// – const correctness: by taking ‘const T&’, this works with both T* and const T* arrays,
//   because you can’t bind a non‑const reference to a const object.
template <typename T>

void iter(const T *array, std::size_t length, void (*f)(const T &)) {
    for (std::size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

template <typename T>

void printElem_const(const T &element) {
    std::cout << element << "\n";
}

template <typename T>

void printElem(T &element) {
    std::cout << element << "\n";
}

#endif


#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> //std::find()
#include <stdexcept> // std::out_of_range

//  non‑const overload: returns a mutable iterator
template <typename T>

typename T::iterator easyfind(T &container, int target) {
    typename T::iterator it = std::find(container.begin(), container.end(), target);
    if (it == container.end())
        throw std::out_of_range("easyfind: value not in container");
    return it;
}

template <typename T>

// <const_iterator> Acts like a pointer to a mutable element.
// an iterator type that lets you traverse a container’s elements but only read them

typename T::const_iterator easyfind(const T &container, int target) {
    // Inside a template, T::const_iterator is a nested dependent name (the compiler doesn’t yet
    // know what T is), so you must prefix it with typename to tell the compiler “this is a type,”
    // otherwise you get a parse error.
    typename T::const_iterator iter = std::find(container.begin(), container.end(), target);

    if (iter == container.end()) {
        throw std::out_of_range("easyfind: value not in container");
    }
    return iter;
}

#endif





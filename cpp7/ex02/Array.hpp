
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // for out_of_range
#include <iostream>
#include <string>
#include <typeinfo>

//  a class only becomes a class template
// if you put a template<…> header in front of its declaration.
template <typename T> class Array {
  private:
    unsigned int _size;
    T *_array;

  public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    unsigned int size() const;
    // const on a member function is part of its signature
    T &operator[](unsigned int n);
    const T &operator[](unsigned int n) const;
};

#include "Array.tpp" // ← definitions only _after_ the template is declared

#endif

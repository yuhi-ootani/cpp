

#include "Serializer.hpp"

Serializer::Serializer() { std::cout << "Serializer default constructor\n"; }

Serializer::Serializer(const Serializer &other) {
    (void)other;
    std::cout << "Serializer copy constructor (nothing happen) \n";
}

Serializer &Serializer::operator=(const Serializer &other) {
    (void)other;
    std::cout << "Serializer operator assignment (nothing happen) \n";
    return *this;
}

Serializer::~Serializer() { std::cout << "Serializer destructor \n"; }

// uintptr_t is an unsigned integer type that’s guaranteed to be large enough to hold any pointer
// value on your platform.

// benefit
// Serialization / persistence You can pack raw into a file, send it over the wire,
// or stash it in a database, then later turn it back into the exact same pointer by doing
// reinterpret_cast<Data *>(raw)

uintptr_t Serializer::serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data *Serializer::deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }


#include "baseABC.hpp"

Base::~Base() { std::cout << "Base destructor called\n"; }

Base *generate(void) {
    int random_value = std::rand();
    if (random_value % 3 == 0) {
        return new A();
    } else if (random_value % 3 == 1)
        return new B();
    else
        return new C();
}

// dynamic_cast<Derived*>(basePtr) checks at run‑time if *basePtr really points to a Derived object
// (or class derived from it).
// On success: returns that pointer, typed as Derived*.
// On failure: returns nullptr.
void identify(Base *p) {
    if (A *a = dynamic_cast<A *>(p))
        std::cout << "It's a class A\n";
    else if (B *b = dynamic_cast<B *>(p))
        std::cout << "It's a class B\n";
    else if (C *c = dynamic_cast<C *>(p))
        std::cout << "It's a class C\n";
    else
        std::cout << "It's not a Class ABC";
}

// dynamic_cast<Derived&>(baseRef) also checks at run‑time if baseRef really refers to a Derived.
// On success: returns that reference, typed as Derived&.
// On failure: it throws a std::bad_cast exception.
void identify(Base &p) {
    try {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "It's a class A\n";
        return;
    } catch (...) {
        ;
    }

    try {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "It's a class B\n";
        return;
    } catch (...) {
        ;
    }

    try {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "It's a class C\n";
        return;
    } catch (...) {
        ;
    }
    std::cout << "It's not a Class ABC";
    return;
}

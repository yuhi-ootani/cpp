
#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Address of str      : " << &str << std::endl;
    std::cout << "Address of stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of stringREF: " << &stringREF << std::endl;

    std::cout << "Address of str      : " << str << std::endl;
    std::cout << "Address of stringPTR: " << *stringPTR << std::endl;
    std::cout << "Address of stringREF: " << stringREF << std::endl;

    return 0;
}


// | Feature                      | Pointer (`T*`)                                                     | Reference (`T&`)                                                                               |
// | ---------------------------- | ------------------------------------------------------------------ | ---------------------------------------------------------------------------------------------- |
// | **Declaration**              | `T* p;`                                                            | `T& r = obj;`                                                                                  |
// | **Initialization**           | Can be uninitialized (garbage)                                     | **Must** be initialized to a valid object                                                      |
// | **Nullability**              | Can be `nullptr` (no target)                                       | Cannot be null; always aliases something                                                       |
// | **Re-assignment**            | Can be reseated to point elsewhere                                 | Cannot be reseated after initialization                                                        |
// | **Syntax for use**           | Dereference with `*p`, access members via `p->…`                   | No special operator—use `r` directly                                                           |
// | **Memory footprint**         | Occupies storage (typically the size of an address)                | Usually just an alias—no extra storage (though compiler may implement internally as a pointer) |
// | **Pointer arithmetic**       | Supported (e.g. `p+1`, `p-1`)                                      | Not supported                                                                                  |
// | **Arrays**                   | You can have arrays of pointers                                    | You cannot have arrays of references                                                           |
// | **Rebinding to temporaries** | You can point to a temporary (dangling if not careful)             | Cannot bind to non-const temporaries; `const T&` can bind to a temporary                       |
// | **Use cases**                | Dynamic data structures, manual memory management, optional values | Safe aliasing, operator overloading, polymorphic function arguments                            |

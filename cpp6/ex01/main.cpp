

#include "Serializer.hpp"

int main() {
    Data me = {"Yuhi", 24};

    std::cout << "\n=== before ===\n";
    std::cout << "Name: " << me.name << " Age: " << me.age << "\nAddress: " << &me << "\n";

    std::cout << "\n=== serialize ===\n";
    uintptr_t int_address = Serializer::serialize(&me);
    std::cout << "Address in int: " << int_address << "\n";

    std::cout << "\n=== deserialize ===\n";
    Data *me_ptr = Serializer::deserialize(int_address);
    std::cout << "Name: " << me_ptr->name << " Age: " << me_ptr->age << "\nAddress: " << me_ptr
              << "\n";

    std::cout << "\n=== address check ===\n";
    if (me_ptr == &me) {
        std::cout << "the original address and the deserialized address are same!\n\n";
    }

    return 0;
}

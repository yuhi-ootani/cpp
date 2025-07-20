
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void check_virtual_destructor() {
    Animal *zoo[10];

    std::cout << "\n ||||||||||||||| create animal array |||||||||||||\n" << std::endl;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            zoo[i] = new Dog();
            std::cout << std::endl;
        } else {
            zoo[i] = new Cat();
            std::cout << std::endl;
        }
    }
    std::cout << "\n ||||||||||||||| delete animal array |||||||||||||\n" << std::endl;
    for (int i = 0; i < 10; i++) {
        delete zoo[i];
        std::cout << std::endl;
    }
}

void check_deep_copy(const Cat &tama) {
    std::cout << "\n//////////////// TEMP1 COPY CONSTRUCTOR //////////////\n";
    Cat temp1(tama);
    temp1.makeSound();
    std::cout << "\n//////////////// TEMP2 ASSINMENT OPERATOR //////////////\n";
    Cat temp2;
    temp2 = tama;
    std::cout << "\n//////////////// TEMP DELETED //////////////\n";
}

// 深いコピーテスト（Dog）
void test_deep_copy_dog() {
    std::cout << "\n=== Dog deep copy ===\n";
    Dog basic;
    {
        std::cout << "\n=== tmp1 copy constructor ===\n";
        Dog tmp1(basic);
        std::cout << "\n=== tmp2 assignment constructor  ===\n";
        Dog tmp2;
        tmp2 = basic;
        std::cout << "\n=== end of scope  ===\n";
    }
    std::cout << "\n====== After tmp scope, basic Brain ptr still valid =======\n";
}

int main() {

    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j;
    delete i;

    //
    check_virtual_destructor();

    test_deep_copy_dog();

    std::cout << "\n///////   test of deep copy CAT!!   //////\n";
    // deep copy
    Cat tama;
    std::cout << "////////TAMA WAS CREATED///////////////\n\n";
    check_deep_copy(tama);
    std::cout << "\n//////temp brain destructed, but tama's brain is still there.///////\n";

    return 0;
}
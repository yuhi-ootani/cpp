
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    Animal *zoo[10];
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j; 
    delete i;

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
    return 0;
}
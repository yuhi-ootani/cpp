
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void pdf_test() {
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
}

void wrong_pdf_test() {
    const WrongAnimal *meta = new WrongAnimal();
    const WrongAnimal *i = new WrongCat();
    std::cout << meta->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    meta->makeSound();
    i->makeSound();

    delete meta;
    delete i;
}

int main() {

    std::cout << "=== correct pdf test ===\n";
    pdf_test();
    std::cout << "\n\n";

    std::cout << "=== wrong pdf test ===\n";
    wrong_pdf_test();
    std::cout << "\n\n";

    std::cout << "=== stack-based Animal ===\n";
    Animal animal;
    std::cout << "type is " << animal.getType() << "\n";
    animal.makeSound();
    std::cout << "\n";

    Animal *mix = new Animal();
    mix->makeSound();
    delete mix;
    mix = new Cat();
    mix->makeSound();
    delete mix;
    mix = new Dog();
    mix->makeSound();
    delete mix;

    std::cout << "\n=== copy tests ===\n";
    Animal a_orig;
    Animal a_copy(a_orig);
    Animal a_assigned;
    a_assigned = a_orig;
    std::cout << "a_copy type:     " << a_copy.getType() << "\n";
    std::cout << "a_assigned type: " << a_assigned.getType() << "\n\n";

    Cat c_orig;
    Cat c_copy(c_orig);
    Cat c_assigned;
    c_assigned = c_orig;
    std::cout << "c_copy type:     " << c_copy.getType() << "\n";
    std::cout << "c_assigned type: " << c_assigned.getType() << "\n\n";

    Dog d_orig;
    Dog d_copy(d_orig);
    Dog d_assigned;
    d_assigned = d_orig;
    std::cout << "d_copy type:     " << d_copy.getType() << "\n";
    std::cout << "d_assigned type: " << d_assigned.getType() << "\n\n";

    return 0;
}

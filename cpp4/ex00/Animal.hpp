

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

// if there is not virtual member function,
// You don't need to add virtual to the destructor
class Animal {
  protected:
    std::string _type;

  public:
    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    // member function
    virtual void makeSound() const;
    std::string getType() const;
};

#endif
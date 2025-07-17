
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// int main() {
//     ScavTrap aaa("aaaa");

//     return 0;
// };

class Base {
  public:
    Base(int x) { std::cout << x << "Base( dsfasdfasdfsdf )\n"; }
};

class Derived : public Base {
    int a_, b_;

  public:
    Derived(int x, int y, int z)
        : Base(x) // ① call the Base(int) ctor
          ,
          a_(y) // ② init member a_
          ,
          b_(z) // ③ init member b_
    {
        std::cout << a_ << " " << b_ << " Derived body\n";
    }
};

int main() { Derived d(1, 2, 3); }

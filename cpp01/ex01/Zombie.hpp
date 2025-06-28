
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
  private:
    std::string _name;

  public:
    Zombie(void) : _name("Unnamed") {}
    Zombie(std::string name);
    ~Zombie();
    void setName(const std::string &name) { _name = name; }
    void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP
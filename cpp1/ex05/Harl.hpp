
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
// DISPATCH TABLE

class Harl {
  private:
    typedef void (Harl::*HarlFoo)(void);

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    // static data member is a variable that belongs to the class itself
    static const int NUM_LEVELS = 4;
    static const char *_levels[4];
    static const Harl::HarlFoo _actions[4];

  public:
    void complain(std::string level);
};



#endif
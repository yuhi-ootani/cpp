
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

struct FormList {
    const std::string name;
    AForm *(*FormCreator)(const std::string &);
};

class Intern {
  private:
    //  in‑class initializer, a static const integral (or enum) member are allowed
    static AForm *makeShrubbery(const std::string &target);
    static AForm *makeRobotomy(const std::string &target);
    static AForm *makePresidential(const std::string &target);
    static const FormList FormTable[];

  public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm *makeForm(const std::string &name, const std::string target) const;
};

#endif


#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() { std::cout << "default Intern constructor called\n"; }

Intern::Intern(const Intern &other) {
    std::cout << " Intern copy-constructor called (nothing coppied)\n";
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    std::cout << " Intern assigment operator called (nothing coppied)\n";
    return *this;
}

Intern::~Intern() { std::cout << "Intern destructor called\n"; }

AForm *Intern::makeShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(const std::string &target) { return new RobotomyRequestForm(target); }

AForm *Intern::makePresidential(const std::string &target) {
    return new PresidentialPardonForm(target);
}

const FormList Intern::FormTable[] = {{"shrubbery creation", &Intern::makeShrubbery},
                                      {"robotomy request", &Intern::makeRobotomy},
                                      {"presidential pardon", &Intern::makePresidential}};

AForm *Intern::makeForm(const std::string &name, const std::string target) const {
    for (unsigned long i = 0; i < sizeof(Intern::FormTable) / sizeof(Intern::FormTable[0]); i++) {
        if (name == Intern::FormTable[i].name) {
            std::cout << "Intern creates " << name << ".\n";
            return Intern::FormTable[i].FormCreator(target);
        }
    }
    std::cout << "Intern: Form " << name << " doesn't exits.\n";
    return NULL;
}

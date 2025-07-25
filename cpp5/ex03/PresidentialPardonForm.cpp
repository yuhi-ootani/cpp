

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// OrthodoxCanonical AForm
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential pardon", 25, 5), _target("undefined") {
    std::cout << _target << " : " << this->getName()
              << " default(unnamed) Form constructor called.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {
    std::cout << _target << " : " << this->getName() << " Form copy-constructor called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    std::cout << _target << " : "
              << "Form assigment operator called. " << other.getName()
              << "'s signed status and target were only copied.💀\n";
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << _target << " : " << this->getName() << " Form destructor called (derived).\n";
}

// paramator constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm("Presidential pardon", 25, 5), _target(target) {
    std::cout << _target << ": " << this->getName() << " Form constructor called\n";
}

// pure virtual function
void PresidentialPardonForm::doExecute() const {
    std::cout << getName() << ": " << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}

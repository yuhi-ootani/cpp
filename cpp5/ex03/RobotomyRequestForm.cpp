

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// OrthodoxCanonical AForm
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy request", 72, 45), _target("undefined") {
    std::cout << _target << " : " << this->getName()
              << " default(unnamed) Form constructor called.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {
    std::cout << _target << " : " << this->getName() << " Form copy-constructor called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    std::cout << _target << " : "
              << "Form assigment operator called. " << other.getName()
              << "'s signed status and target were only copied.💀\n";
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << _target << " : " << this->getName() << " Form destructor called (derived).\n";
}

// paramator constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("Robotomy request", 72, 45), _target(target) {
    std::cout << _target << ": " << this->getName() << " Form constructor called\n";
}

// pure virtual function
void RobotomyRequestForm::doExecute() const {
    std::cout << getName() << ": Bzzzzzzzzzzzzzzzzzzzzzzzzzzz (Drilling noises) \n";

    // std::rand(): Returns the next number in the pseudo‑random sequence
    bool success = ((std::rand() % 2) == 0);

    if (success)
        std::cout << getName() << ": " << _target << " has been robotomized successfully!\n";
    else
        std::cout << getName() << ": " << _target << " failed to be robotomized!\n";
}

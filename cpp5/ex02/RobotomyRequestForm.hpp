

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> // std::rand, std::srand
#include <ctime>   // std::time
#include <iostream>
#include <string>

class Bureaucrat;

class RobotomyRequestForm : public AForm {

  private:
    std::string _target;

  public:
    // OrthodoxCanonical AForm
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    // paramator constructor
    RobotomyRequestForm(const std::string target);

    // pure virtual function
    void doExecute() const;
};

#endif

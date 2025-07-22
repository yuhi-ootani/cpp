
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm {

  private:
    std::string _target;

  public:
    // OrthodoxCanonical AForm
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    // paramator constructor
    PresidentialPardonForm(const std::string target);

    // pure virtual function
    void doExecute() const;
};

#endif

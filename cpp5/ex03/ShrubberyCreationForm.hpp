
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

class Bureaucrat;

class ShrubberyCreationForm : public AForm {

  private:
    std::string _target;

  public:
    // OrthodoxCanonical AForm
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    // paramator constructor
    ShrubberyCreationForm(const std::string target);

    // pure virtual function
    void doExecute() const;
};

void writeTrees(std::ofstream &ofs);

#endif

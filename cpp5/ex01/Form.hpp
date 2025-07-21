
#ifndef FORM_HPP
#define FORM_HPP


#include <iostream>
#include <string>

class Bureaucrat;

class Form {
  private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

  public:
    // OrthodoxCanonical Form
    Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    // constructor
    Form(const std::string name, const int gradeToSing, const int GradeToExecute);

    // getter
    const std::string &getName() const;
    const bool &getIsSigned() const;
    const int &getGradeToSign() const;
    const int &getGradeToExecute() const;

    // member function
    static int validateGrade(const int grade);
    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighExeption : public std::exception {
        virtual const char *what() const throw();
    };

    class GradeTooLowExeption : public std::exception {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif

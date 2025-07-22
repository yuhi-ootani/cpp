
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
  private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

  public:
    // OrthodoxCanonical AForm
    AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    // constructor
    AForm(const std::string name, const int gradeToSign, const int GradeToExecute);

    // getter
    const std::string &getName() const;
    const bool &getIsSigned() const;
    const int &getGradeToSign() const;
    const int &getGradeToExecute() const;

    // member function
    static int validateGrade(const int grade);
    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };

    // --ex02--
    class NotSignedException : public std::exception {
        virtual const char *what() const throw();
    };

    void execute(Bureaucrat const &executor) const;
    virtual void doExecute() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &Aform);

#endif

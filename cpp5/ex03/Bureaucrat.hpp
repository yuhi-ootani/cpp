
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

// 前方宣言 Forward-declaring
class AForm;

class Bureaucrat {

  private:
    const std::string _name;
    int _grade;

  public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    // member function
    std::string getName() const;
    int getGrade() const;
    void gradeUp();
    void gradeDown();

    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    // ex01
    void signForm(AForm &form);

    // ex02
    void executeForm(AForm const &form) const;
};

// overload
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif

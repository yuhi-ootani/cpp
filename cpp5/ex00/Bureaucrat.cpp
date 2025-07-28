
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Tarou"), _grade(150) {
    std::cout << "default(Tarou, 150) Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
    std::cout << name << " Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
    std::cout << other._name << " Bureaucrat copy-constructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        // this->_name = other._name;
        this->_grade = other._grade;
    }
    std::cout << other._name << " Bureaucrat assigment operator called\n";
    return *this;
}

Bureaucrat::~Bureaucrat() { std::cout << this->_name << " Bureaucrat destructor called\n"; }

// member function
std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::gradeUp() {
    if (this->_grade == 1) {
        throw GradeTooHighException();
    }
    (this->_grade)--;
}

void Bureaucrat::gradeDown() {
    if (this->_grade == 150) {
        throw GradeTooLowException();
    }
    (this->_grade)++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade is too HIGH!!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too LOW!!";
}

// overload
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

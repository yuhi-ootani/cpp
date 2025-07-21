
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("unnamed"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "default(unnamed, 150, 150) Form constructor called\n";
}

Form::Form(const Form &other)
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {
    std::cout << other._name << " Form copy-constructor called\n";
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    std::cout << "Form assigment operator called.\n"
              << other._name << "'s signed status was only copied.\n";
    return *this;
}

Form::~Form() { std::cout << this->_name << " Form destructor called\n"; }

// parametor constructor
Form::Form(const std::string name, const int gradeToSign, const int GradeToExecute)
    : _name(name), _signed(false), _gradeToSign(validateGrade(gradeToSign)),
      _gradeToExecute(validateGrade(GradeToExecute)) {
    std::cout << name << " Form constructor called\n";
}

// member function
int Form::validateGrade(const int value) {
    if (value < 1)
        throw GradeTooHighExeption();
    if (value > 150)
        throw GradeTooLowExeption();
    return value;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    int value = validateGrade(bureaucrat.getGrade());
    if (value > _gradeToSign)
        throw GradeTooLowExeption();
    _signed = true;
}

// getter
const std::string &Form::getName() const { return _name; }
const bool &Form::getIsSigned() const { return _signed; }
const int &Form::getGradeToSign() const { return _gradeToSign; }
const int &Form::getGradeToExecute() const { return _gradeToExecute; }

// subclass
const char *Form::GradeTooHighExeption::what() const throw() {
    return "The grade is too HIGH for Form!!";
}

const char *Form::GradeTooLowExeption::what() const throw() {
    return "The grade is too LOW for Form!!";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form name : " << form.getName() << "\n"
       << "Is signed : " << form.getIsSigned() << "\n"
       << "Minimum grade to sign : " << form.getGradeToSign() << "\n"
       << "Minimum grade to execute : " << form.getGradeToExecute() << "\n";
    return os;
}


#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("unnamed"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "default(unnamed, 150, 150) Form constructor called\n";
}

AForm::AForm(const AForm &other)
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {
    std::cout << other._name << " Form copy-constructor called\n";
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    std::cout << "Form assigment operator called.\n"
              << other._name << "'s signed status was only copied.💀\n";
    return *this;
}

AForm::~AForm() { std::cout << this->_name << " Form destructor called\n"; }

// parametor constructor
AForm::AForm(const std::string name, const int gradeToSign, const int GradeToExecute)
    : _name(name), _signed(false), _gradeToSign(validateGrade(gradeToSign)),
      _gradeToExecute(validateGrade(GradeToExecute)) {
    std::cout << name << " Form constructor called\n";
}

// member function
int AForm::validateGrade(const int value) {
    if (value < 1)
        throw GradeTooHighException();
    if (value > 150)
        throw GradeTooLowException();
    return value;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    int value = validateGrade(bureaucrat.getGrade());
    if (value > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

// getter
const std::string &AForm::getName() const { return _name; }
const bool &AForm::getIsSigned() const { return _signed; }
const int &AForm::getGradeToSign() const { return _gradeToSign; }
const int &AForm::getGradeToExecute() const { return _gradeToExecute; }

// subclass
const char *AForm::GradeTooHighException::what() const throw() {
    return "The grade is too HIGH for Form!!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "The grade is too LOW for Form!!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "Form name : " << form.getName() << "\n"
       << "Is signed : " << form.getIsSigned() << "\n"
       << "Minimum grade to sign : " << form.getGradeToSign() << "\n"
       << "Minimum grade to execute : " << form.getGradeToExecute() << "\n";
    return os;
}

// --ex02--
void AForm::execute(Bureaucrat const &executor) const {
    if (this->getIsSigned() != true)
        throw NotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    this->doExecute();
}

const char *AForm::NotSignedException::what() const throw() {
    return "The form is not signed yet.";
}
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    Bureaucrat Trump("Trump", 1);
    Intern student;

    std::cout << "\n======= create shrubbery form =======\n";
    AForm *CreatedForm = student.makeForm("shrubbery creation", "target");
    if (CreatedForm) {
        try {
            CreatedForm->beSigned(Trump);
            CreatedForm->execute(Trump);
        } catch (std::exception &e) {
            std::cout << e.what() << "\n";
        }
        delete CreatedForm;
    }

    std::cout << "\n======= create robotory form =======\n";
    CreatedForm = student.makeForm("robotomy request", "target");
    if (CreatedForm) {
        try {
            CreatedForm->beSigned(Trump);
            CreatedForm->execute(Trump);
        } catch (std::exception &e) {
            std::cout << e.what() << "\n";
        }
        delete CreatedForm;
    }

    std::cout << "\n======= create presidential form =======\n";
    CreatedForm = student.makeForm("presidential pardon", "target");
    if (CreatedForm) {
        Trump.signForm(*CreatedForm);
        Trump.executeForm(*CreatedForm);
        delete CreatedForm;
    }

    std::cout << "\n=======  Form doesn't exit =======\n";
    CreatedForm = student.makeForm("nonexistent", "target");
    if (CreatedForm) {
        try {
            CreatedForm->beSigned(Trump);
            CreatedForm->execute(Trump);
        } catch (std::exception &e) {
            std::cout << e.what() << "\n";
        }
        delete CreatedForm;
    }

    std::cout << "\n=======  fin =======\n";
    return 0;
}

// // direved form test
// void test_direved_form(AForm *form, int signGrade, int execuGrade) {
//     Bureaucrat signer("signer", signGrade);
//     Bureaucrat executor("Executor", execuGrade);

//     std::cout << "\n======= ERROR: execute without sign =======\n";
//     try {
//         form->execute(executor);
//     } catch (std::exception &e) {
//         std::cerr << e.what() << "\n";
//     }

//     std::cout << "\n======= ERROR: too low grade to execute =======\n";
//     try {
//         form->beSigned(signer);
//         form->execute(signer);
//     } catch (std::exception &e) {
//         std::cerr << e.what() << "\n";
//     }

//     std::cout << "\n======= executeForm test (execute) =======\n";
//     try {
//         form->execute(executor);
//     } catch (std::exception &e) {
//         std::cerr << e.what() << "\n";
//     }

//     std::cout << "\n======= executeForm test (executeForm) =======\n";
//     try {
//         executor.executeForm(*form);
//         signer.executeForm(*form);
//     } catch (std::exception &e) {
//         std::cerr << e.what() << "\n";
//     }

//     std::cout << "\n======= exit function =======\n";
// }

// int main() {
//     // ========= setting up ================ //
//     // std::time(nullptr):
//     // Returns the current calendar time as a std::time_t (passing null = for “right now.”)
//     // std::srand(seed): Initializes (seeds). should call ONCE!
//     std::srand(static_cast<unsigned>(std::time(NULL)));

//     // It turns on the “boolalpha” format flag so that any bool output as true/false.
//     std::cout.setf(std::ios::boolalpha);
//     // ========= setting up ================ //

//     // ========= test ============== //

//     // AForm abstract test
//     // AForm IsAbstract;

//     // concrete classes test
//     std::cout << "\n\n======= ShrubberyCreationForm constructor test =======\n";
//     {
//         ShrubberyCreationForm undefined;
//         std::cout << "\n";

//         ShrubberyCreationForm bery("bery");
//         std::cout << "\n";

//         ShrubberyCreationForm copy(bery);
//         std::cout << "\n";

//         undefined = bery;
//         std::cout << "\n";
//     }

//     std::cout << "\n\n======= RobotomyRequestForm constructor test =======\n";
//     {
//         RobotomyRequestForm undefined;
//         std::cout << "\n";

//         RobotomyRequestForm bery("Robot");
//         std::cout << "\n";

//         RobotomyRequestForm copy(bery);
//         std::cout << "\n";

//         undefined = bery;
//         std::cout << "\n";
//     }

//     std::cout << "\n\n======= PresidentialPardonForm constructor test =======\n";
//     {
//         PresidentialPardonForm undefined;
//         std::cout << "\n";

//         PresidentialPardonForm bery("President");
//         std::cout << "\n";

//         PresidentialPardonForm copy(bery);
//         std::cout << "\n";

//         undefined = bery;
//         std::cout << "\n";
//         }

//     std::cout << "\n*************** ShrubberyCreationForm work test ***************\n";
//     AForm *testShruberry = new ShrubberyCreationForm("testS");
//     test_direved_form(testShruberry, 138, 137);
//     delete testShruberry;

//     std::cout << "\n*************** RobotomyRequestForm work test ***************\n";
//     AForm *testRobotomy = new RobotomyRequestForm("testR");
//     test_direved_form(testRobotomy, 46, 45);
//     delete testRobotomy;

//     std::cout << "\n*************** PresidentialPardonForm work test ***************\n";
//     AForm *testPresident = new PresidentialPardonForm("testP");
//     test_direved_form(testPresident, 6, 5);
//     delete testPresident;

//     return 0;
// }

// // default constructor | destructor
// std::cout << "\n-- default constructor --\n";
// {
//     Form default_form;
//     std::cout << default_form << "\n";
//     std::cout << "\n-- destructor -- \n";
// }

// // Copy constructor | parameters constructor | getter | insertion overload
// std::cout << "\n-- parameters constructor -- \n";
// {
//     Form orig("Original", 42, 42);
//     std::cout << "\n-- getter function -- \n";
//     std::cout << orig.getName() << " is signed " << orig.getIsSigned()
//               << "  grade(sign) : " << orig.getGradeToSign()
//               << " grade(execute) : " << orig.getGradeToExecute() << "\n";
//     std::cout << "\n-- copy constructor -- \n";
//     Form copy(orig);
//     std::cout << "\n-- insertion overload -- \n";
//     std::cout << copy << "\n";
// }

// // Grade is out of range
// std::cout << "\n-- grade is out of range --\n";
// {
//     try {
//         Form High("High", 151, 150);
//     } catch (const std::exception &e) {
//         std::cerr << e.what() << "\n";
//     }
//     try {
//         Form Low("Low", 1, 0);
//     } catch (const std::exception &e) {
//         std::cerr << e.what() << "\n";
//     }
//     try {
//         Form Both("Both", 0, 1519);
//     } catch (const std::exception &e) {
//         std::cerr << e.what() << "\n";
//     }
// }

// // beSigned Test | Assignment operator
// std::cout << "\n-- beSigned test -- \n";
// {
//     Form toTrue("Source", 88, 88);
//     {
//         Bureaucrat Trump("Trump", 1);
//         Bureaucrat Baby("Baby", 150);
//         try {
//             toTrue.beSigned(Trump);
//             std::cout << Trump << " signed " << toTrue.getName() << "\n";
//             std::cout << toTrue << "\n";

//             toTrue.beSigned(Baby);
//             // NEVER CALLED
//             std::cout << Baby << "signed" << toTrue << "\n";
//         } catch (const std::exception &e) {
//             std::cout << e.what() << "\n";
//         }

//         std::cout << "\n-- signForm  --\n";
//         Form temp("temp", 100, 80);
//         Trump.signForm(temp);
//         Baby.signForm(temp);
//     }

//     std::cout << "\n-- Assignment operator  --\n";
//     Form dst("Dest", 100, 100);
//     std::cout << "before: dst = " << dst << "\n";
//     dst = toTrue;
//     std::cout << "after : dst = " << dst << "\n";
// }

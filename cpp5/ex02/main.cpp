#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    // std::time(nullptr):
    // Returns the current calendar time as a std::time_t (passing null = for “right now.”)

    // std::srand(seed): Initializes (seeds). should call ONCE!
    std::srand(static_cast<unsigned>(std::time(NULL)));

    std::cout.setf(std::ios::boolalpha);

    // default constructor | destructor
    std::cout << "\n-- default constructor --\n";
    {
        Form default_form;
        std::cout << default_form << "\n";
        std::cout << "\n-- destructor -- \n";
    }

    // Copy constructor | parameters constructor | getter | insertion overload
    std::cout << "\n-- parameters constructor -- \n";
    {
        Form orig("Original", 42, 42);
        std::cout << "\n-- getter function -- \n";
        std::cout << orig.getName() << " is signed " << orig.getIsSigned()
                  << "  grade(sign) : " << orig.getGradeToSign()
                  << " grade(execute) : " << orig.getGradeToExecute() << "\n";
        std::cout << "\n-- copy constructor -- \n";
        Form copy(orig);
        std::cout << "\n-- insertion overload -- \n";
        std::cout << copy << "\n";
    }

    // Grade is out of range
    std::cout << "\n-- grade is out of range --\n";
    {
        try {
            Form High("High", 151, 150);
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
        try {
            Form Low("Low", 1, 0);
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
        try {
            Form Both("Both", 0, 1519);
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }

    // beSigned Test | Assignment operator
    std::cout << "\n-- beSigned test -- \n";
    {
        Form toTrue("Source", 88, 88);
        {
            Bureaucrat Trump("Trump", 1);
            Bureaucrat Baby("Baby", 150);
            try {
                toTrue.beSigned(Trump);
                std::cout << Trump << " signed " << toTrue.getName() << "\n";
                std::cout << toTrue << "\n";

                toTrue.beSigned(Baby);
                // NEVER CALLED
                std::cout << Baby << "signed" << toTrue << "\n";
            } catch (const std::exception &e) {
                std::cout << e.what() << "\n";
            }

            std::cout << "\n-- signForm  --\n";
            Form temp("temp", 100, 80);
            Trump.signForm(temp);
            Baby.signForm(temp);
        }

        std::cout << "\n-- Assignment operator  --\n";
        Form dst("Dest", 100, 100);
        std::cout << "before: dst = " << dst << "\n";
        dst = toTrue;
        std::cout << "after : dst = " << dst << "\n";
    }

    return 0;
}

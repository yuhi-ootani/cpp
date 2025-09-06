
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// OrthodoxCanonical AForm
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("shrubbery creation", 145, 137), _target("undefined") {
    std::cout << _target << ": " << this->getName()
              << " default(unnamed) Form constructor called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {
    std::cout << _target << ": " << this->getName() << " Form copy-constructor called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    std::cout << _target << ": "
              << "Form assigment operator called. " << other.getName()
              << "'s signed status and target were only copied.💀\n";
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << _target << ": " << this->getName() << " Form destructor called (derived).\n";
}

// paramator constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("shrubbery creation", 145, 137), _target(target) {
    std::cout << _target << ": " << this->getName() << " Form constructor called\n";
}

// pure virtual function
void ShrubberyCreationForm::doExecute() const {

    std::string filename = _target + "_shrubbery";
    // std::ofstream—expect a const char* (a “C‑string”) rather than a std::string object
    std::ofstream ofs(filename.c_str());
    if (!ofs) {
        std::cerr << "Error: couldn't open file " << filename << ".\n";
        return;
    }
    writeTrees(ofs);
    // Close (optional—will be closed automatically in destructor)
    ofs.close();
    std::cout << "Wrote ASCII shrubbery to " << filename << "”\n";
}

void writeTrees(std::ofstream &ofs) {
    ofs << "                          ▏▏\n";
    ofs << "                         ▏▍▇▁▏              ▌▉▂▋▎               ▏▎▎▍▋▊▍▎\n";
    ofs << "                       ▏▌▏ ▄█▄▎          ▎▌▁▍ ▌██▆▉▎          ▏▏▏    ▍▁█▆▉▏\n";
    ofs << "                       ▉▏  ▎▅█▆▋        ▎▋▏    ▌▇███▉        ▎▏       ▏▅██▅▍\n";
    ofs << "                     ▏▉▎    ▌▇██▋       ▁▎    ▍▇█████▅     ▏▉▌      ▏▏▏▇███▇▍\n";
    ofs << "                     ▃▁▉▌▋▌▋▁████▌      ▅▂▉▁▎▏▌▎▇████▇     ▎▇▁▂▊▉▉▁▉▁▃▇████▇▌\n";
    ofs << "                    ▏▊▊▉▁▁▁▄▇████▊     ▏▊▁▌▌▎▌▅██████▃▎    ▎▍▊▋▊▉▂▅▅▄▆█████▆▊▏\n";
    ofs << "                   ▍▅▍▏     ▏▌▆███▋   ▏▃▎     ▎▁▃█████▆▎  ▋▁▏       ▎▋▍▅█████▆▏\n";
    ofs << "              ▏▏▌▃▍▎▂▄▆▅▆▇█▇▇█████▆   ▌█▄▊▉▌▍▍▌▊▆██████▄  ▃▅▌▌▎▌▋▊▋▉▄████████▅▏\n";
    ofs << "             ▏▏  ▊█▄▏   ▎▎▎▎▉▆█████▁  ▏▁▅▂▂▂▇█▅████████▁  ▎▃▄▃▆▆▆▇███████████▂▎\n";
    ofs << "            ▏▎   ▋██▄▁▉▍▊▋▊▊▉▇██████▌▎▃▎    ▏▎ ▊███████▍ ▋▊▏      ▏▍▌▌▆███████▇▍\n";
    ofs << "           ▍▏    ▏████▄▄▆▆▇█▇██████▆▏▍█▋▎▏▏▃▃▂▄████████▇ █▂▍▏     ▏▎▉▇█████████▃\n";
    ofs << "           ▉▃▂▉▁▃▄████▉     ▏▄██████▅▌▇████████████████▁ ▂██▇▆▃▁▁▂▄███████████▇▊\n";
    ofs << "          ▍▏▏▎▎▋▋▉▅████▂▉▉▉▃▄███████▇▍▏▂██████████████▂▏  ▌▁▆██████████████▇▂▊▎\n";
    ofs << "         ▎▅▄▄▂▂▂▃▃▇████▆▇███████████▁    ▌▊▊▂████▉▅▃▍▏       ▏▋▄▄▄████▅▂▄▅▍\n";
    ofs << "        ▏▋▌▍▌▋▁▉▁▂▄▅███▇▉▎▍▍▅████████▉▏     ▎▃███▃▂▏           ▌▂▏▄██▇ ▏▁▋\n";
    ofs << "        ▉▂▌▌▍▎▎▎▍▍▋▃█████▉▍▌▄█████████▉    ▎▌▃███▍              ▊▄▆██▇▌▃▋▏\n";
    ofs << "        ▍▃▄▄▆▆▆██████████████████████▇▋     ▋▅███                ▏▆███▂▏ \n";
    ofs << "      ▏▃▌     ▏▎▍▋▅██████████▃▅▁▉▂▋▊▋▏       ▂███▁▏               ▅███   \n";
    ofs << "      ▏▉█▆▃▂▂▁▂▂▂▂▇█████████▇                ▂███▏                ▅███▎  \n";
    ofs << "      ▋▌▌▊▊▁▁▃▂▄▆████████████▋▍▍          ▍▊▉████▄▌▏           ▏▌▂████▆▊▌▏\n";
    ofs << "     ▉▆▋▌▎▏▏  ▏▏ ▎▂▇███████████▇▃▋▏     ▋▄█████▆████▅▊▎     ▍▁▇███████████▄▍▎▏ \n";
    ofs << "     ▏▊▃▅███▇▇██▇████████▆▃▋▏▏▏▏▏▏▏     ▏▏▏▏▏▏▏▏▏▏▏▏▏▏▏     ▏▏▏▏▏▏▏▏▏▏▏▏▏▏▏▏▏▏\n";
    ofs << "         ▏▏▎▍▍▊███▅▎ ▎▍▍▍  \n";
    ofs << "              ▋███▅     \n";
    ofs << "  ▏▏▏▏▏▎▏▎▎▍▎▊▃███▇▋▉▍▏▏▎    \n";
    ofs << " ▎▉▂▅▄▃█▅▆▇██▇█████████▆▄▁▎▏    \n";
    ofs << " ▍▍▍▍▍▍▍▍▍▍▍▍▎▍▍▍▎▎▍▍▍▍▍▍▍▍▏     \n";
    ofs << " ▍▍▍▍▍▍▍▍▍▍▍▍▎▍▍▍▎▎▍▍▍▍▍▍▍▍▏    \n";
}

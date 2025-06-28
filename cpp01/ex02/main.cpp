
#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Address of str: " << &str << std::endl;
    std::cout << "Address of str: " << stringPTR << std::endl;
    std::cout << "Address of str: " << &stringREF << std::endl;

    std::cout << "Address of str: " << str << std::endl;
    std::cout << "Address of str: " << *stringPTR << std::endl;
    std::cout << "Address of str: " << stringREF << std::endl;
}


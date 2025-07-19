
#include "PhoneBook.hpp"


int main() {
    std::string input;
    PhoneBook book;
    std::cout << "Welcome to the PhoneBook application!" << std::endl;
    while (true) {
        std::cout << std::endl << "Please enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl;
            break;
        }
        if (input == "ADD") {
            std::cout << "Adding a new contact..." << std::endl;
            if (!book.add_contact()) {
                std::cout << std::endl;
                return 1;
            }
        } else if (input == "SEARCH") {
            std::cout << "Searching for contacts..." << std::endl;
            if (!book.search_contact()) {
                std::cout << std::endl;
                return 2;
            }
        } else if (input == "EXIT") {
            std::cout << "Exiting the PhoneBook application. Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
    return 0;
}

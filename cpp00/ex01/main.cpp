
#include "PhoneBook.hpp"

int main() {
  std::string input;
  PhoneBook phoneBook;
  std::cout << "Welcome to the PhoneBook application!" << std::endl;
  while (true) {
    std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
    std::getline(std::cin, input);
    if (input == "ADD") 
    {
      std::cout << "Adding a new contact..." << std::endl;
      phoneBook.add_contact();  
    } 
    else if (input == "SEARCH") {
      std::cout << "Searching for contacts..." << std::endl;
      phoneBook.search_contact();
    } 
    else if (input == "EXIT")
    {
      std::cout << "Exiting the PhoneBook application. Goodbye!" << std::endl;
      break;  
    } else {
      std::cout << "Invalid command. Please try again." << std::endl;
    }
  }
  return 0;
}

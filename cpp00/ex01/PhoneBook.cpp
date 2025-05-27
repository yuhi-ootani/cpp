
#include "phonebook.hpp"

static void add_contact_error()
{
    std::cout << "Error: Contact could not be added. Please try again." << std::endl;
}

bool PhoneBook::add_contact()
{
    Contact new_contact;
    std::string input;
    
    std::cout << "Enter first name:";
    if (!std::getline(std::cin, input) || !new_contact.set_first_name(input))
        return (add_contact_error(), false);
    
    std::cout << "Enter last name:";
    if (!std::getline(std::cin, input) || !new_contact.set_last_name(input))
        return (add_contact_error(), false);

    std::cout << "Enter nickname:"; 
    if (!std::getline(std::cin, input) || !new_contact.set_nickname(input))
        return (add_contact_error(), false);
    
    std::cout << "Enter phone number:";
    if (!std::getline(std::cin, input) || !new_contact.set_phone_number(input))
        return (add_contact_error(), false);

    std::cout << "Enter darkest secret:";
    if (!std::getline(std::cin, input) || !new_contact.set_darkest_secret(input))
         return (add_contact_error(), false);
    
    contacts[index] = new_contact;
    if (index == 7)
        index = 0; 
    else
        index++;
    std::cout << "Contact added successfully!" << std::endl;
    return true;
}


static void print_table_header()
{
    std::cout << "Contact list:" << std::endl;
    std::cout << std::setw(10) << "Index |"
    << std::setw(10) << "First Name |"
    << std::setw(10) << "Last Name |"
    << std::setw(10) << "Nickname |" << std::endl;
}

static void print_ten_chars(const std::string &str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
    std::cout << "|" << std::endl;
}

void PhoneBook::display_contacts() const 
{
    print_table_header();
    for (int i = 0; i < index; i++) {
        std::cout << std::setw(10) << i << "|";
        print_ten_chars(contacts[i].get_first_name());
        print_ten_chars(contacts[i].get_last_name());
        print_ten_chars(contacts[i].get_nickname());
    }
}

void 


void PhoneBook::search_contact() const 
{
    if(count == 0) {
        std::count << "No contacts available." << std::endl;
        return;
    }
    display_contacts();
    std::cout << "Enter the index of the contact you want to view: ";
    int index;
    std::cin >> index; // may need to handle invalid input
    if(idx < 0 || idx >= 8) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    print_full_contact(contacts[index]);

}
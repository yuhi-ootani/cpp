
#include "PhoneBook.hpp"

/*
=========================================================
  add_contact
=========================================================
*/
static void add_contact_error() {
    std::cout << "Error: Contact could not be added. Please try again." << std::endl;
}

bool PhoneBook::add_contact() {
    Contact new_contact;
    std::string input;

    std::cout << "Enter first name:";
    if (!std::getline(std::cin, input))
        return false;
    if (!new_contact.set_first_name(input))
        return (add_contact_error(), true);

    std::cout << "Enter last name:";
    if (!std::getline(std::cin, input))
        return false;
    if (!new_contact.set_last_name(input))
        return (add_contact_error(), true);

    std::cout << "Enter nickname:";
    if (!std::getline(std::cin, input))
        return false;
    if (!new_contact.set_nickname(input))
        return (add_contact_error(), true);

    std::cout << "Enter phone number:";
    if (!std::getline(std::cin, input))
        return false;
    if (!new_contact.set_phone_number(input))
        return (add_contact_error(), true);

    std::cout << "Enter darkest secret:";
    if (!std::getline(std::cin, input))
        return false;
    if (!new_contact.set_darkest_secret(input))
        return (add_contact_error(), true);

    contacts_[index_] = new_contact;
    count_++;
    if (index_ == 7)
        index_ = 0;
    else
        index_++;
    std::cout << "Contact added successfully!" << std::endl;
    return true;
}

/*
=========================================================
  display_contacts
=========================================================
*/
static void print_table_header() {
    std::cout << "Contact list:" << std::endl;
    std::cout << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;
}

static void print_ten_chars(const std::string &str) {
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
    std::cout << "|";
}

void PhoneBook::display_contacts() const {
    print_table_header();
    int max = (count_ < 8) ? count_ : 8;
    for (int i = 0; i < max; i++) {
        std::cout << std::setw(10) << i;
        std::cout << "|";
        print_ten_chars(contacts_[i].get_first_name());
        print_ten_chars(contacts_[i].get_last_name());
        print_ten_chars(contacts_[i].get_nickname());
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/*
=========================================================
  search_contact
=========================================================
*/
bool PhoneBook::search_contact() const {
    if (count_ == 0) {
        std::cout << "No contacts available." << std::endl;
        return true;
    }

    display_contacts();
    std::cout << "Enter the index of the contact you want to view: ";

    std::string line;
    if (!std::getline(std::cin, line)) {
        return false;
    }

    std::istringstream iss(line);
    int idx;
    if (!(iss >> idx)) {
        std::cout << "Invalid input: please enter a number.\n";
        return true;
    }

    char leftover;
    if (iss >> leftover) {
        std::cout << "Invalid input: only one number allowed.\n";
        return true;
    }

    if (idx < 0 || idx >= count_ || idx >= 8) {
        std::cout << "Invalid index: out of range.\n";
        return true;
    }
    contacts_[idx].print_full_info();
    return true;
}

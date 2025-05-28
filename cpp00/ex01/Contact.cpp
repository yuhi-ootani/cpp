
#include "PhoneBook.hpp"

bool Contact::set_first_name(const std::string &s) {
    if (s.empty()) 
        return false;
    first_name = s;
    return true;
}

bool Contact::set_last_name(const std::string &s) {
    if (s.empty())
        return false;
    last_name = s;
    return true;
}

bool Contact::set_nickname(const std::string &s) {
    if (s.empty())
        return false;
    nickname = s;
    return true;
}

bool Contact::set_phone_number(const std::string &s) {
    if (s.empty())
        return false;
    phone_number = s;
    return true;
}

bool Contact::set_darkest_secret(const std::string &s) {
    if (s.empty())
        return false;
    darkest_secret = s;
    return true;
}

const std::string &Contact::get_first_name() const {
    return first_name;
}

const std::string &Contact::get_last_name() const {
    return last_name;
}

const std::string &Contact::get_nickname() const {
    return nickname;
}

const std::string &Contact::get_phone_number() const {
    return phone_number;
}

const std::string &Contact::get_darkest_secret() const {
    return darkest_secret;
}

void Contact::print_full_info() const {
    std::cout << "First Name    : " << first_name   << "\n"
                  << "Last Name     : " << last_name    << "\n"
                  << "Nickname      : " << nickname    << "\n"
                  << "Phone Number  : " << phone_number << "\n"
                  << "Darkest Secret: " << darkest_secret << "\n";
    
}

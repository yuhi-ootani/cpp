
#ifndef CONTACT_HPP     
#define CONTACT_HPP     

#include <iostream>
#include <string>

class Contact {
 private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

  public:
    // Setters 
    bool set_first_name(const std::string &s);
    bool set_last_name(const std::string &s);
    bool set_nickname(const std::string &s);
    bool set_phone_number(const std::string &s);
    bool set_darkest_secret(const std::string &s);

    // Getters
    const std::string &get_first_name() const;
    const std::string &get_last_name() const;
    const std::string &get_nickname() const;
    const std::string &get_phone_number() const;
    const std::string &get_darkest_secret() const;

    //method
    void print_full_info() const;
    
};

#endif  // CONTACT_HPP      
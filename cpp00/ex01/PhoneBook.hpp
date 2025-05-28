
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
  private:
    Contact contacts[8];
    int index;

  public:
    bool add_contact();
    void display_contacts() const;
    void search_contact() const;

};

#endif  // PHONEBOOK_HPP
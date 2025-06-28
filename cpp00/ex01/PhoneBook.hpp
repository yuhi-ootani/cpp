
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>

#include "Contact.hpp"

class PhoneBook {
 private:
  Contact contacts_[8];
  int count_;
  int index_;

 public:
  PhoneBook() : count_(0), index_(0){};
  ~PhoneBook(){};
  bool add_contact();
  void display_contacts() const;
  bool search_contact() const;
};

#endif  // PHONEBOOK_HPP
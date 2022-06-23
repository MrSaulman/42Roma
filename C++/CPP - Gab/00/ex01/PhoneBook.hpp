#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
    public:
        void init();
        void displayContacts();
        void SearchContact(int index);
        int searchAddIndex();    
        void addContact(int index, std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string secret);

    private:
        Contact contacts[8];
};

#endif
#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>
# include <iostream>
# include <iomanip>

const int MAX_CONTACTS = 8;
const int FIELD_WIDTH = 10;

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        void            setFirstName(std::string);
        void            setLastName(std::string);
        void            setNickName(std::string);
        void            setPhoneNumber(std::string);
        void            setDarkestSecret(std::string);
        std::string     getFirstName(void);
        std::string     getLastName(void);
        std::string     getNickName(void);
        std::string     getPhoneNumber(void);
        std::string     getDarkestSecret(void);
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
};

void showPhonebook(Contact phonebook[], int index);
Contact addContact(void);

#endif
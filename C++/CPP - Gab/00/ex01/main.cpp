#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int index_atoi(std::string index_s);

int main()
{
    PhoneBook phoneBook;
    int index = 0, display_index;
    std::string line, index_c;
    std::string f_name, l_name, nick, number, secret;

    phoneBook.init();

    while(line != "EXIT")
    {
        std::cout << "Use 'ADD' to add a new contact, 'SEARCH' to search for a contact and 'EXIT' to quit the program" << std::endl;
        getline (std::cin, line);
        if (line == "EXIT")
            break;
        else if (line == "ADD")
        {
            index = phoneBook.searchAddIndex();
            std::cout << "First name: ";
            getline (std::cin, f_name);
            std::cout << "Last name: ";
            getline (std::cin, l_name);
            std::cout << "Nickname: ";
            getline (std::cin, nick);
            std::cout << "Number: ";
            getline (std::cin, number);
            std::cout << "Secret: ";
            getline (std::cin, secret);
            phoneBook.addContact(index, f_name, l_name, nick, number, secret);
        }
        else if (line == "SEARCH")
        {
            phoneBook.displayContacts();
            std::cout << std::endl << "Wich index you want to display? ";
            getline (std::cin, index_c);
            display_index = index_atoi(index_c);
            if (display_index == -1)
                std::cout << "index out of range" << std::endl;
            else
                phoneBook.SearchContact(display_index);
        }
        else if (!std::cin.eof()) 
        {
            std::cout << "invalid command, try again" << std::endl;
        }
        if (std::cin.eof())
            break;
    }
    return(0);
}

int index_atoi(std::string index_s)
{
    if((index_s[0] != '0' && index_s[0] != '1' && index_s[0] != '2' && index_s[0] != '3' && index_s[0] != '4' && index_s[0] != '5' && index_s[0] != '6' && index_s[0] != '7') || index_s[1] != '\0')
        return (-1);
    else 
        return ((int)index_s[0] - '0');
}
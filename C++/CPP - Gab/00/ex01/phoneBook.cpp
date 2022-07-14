#include "contactClass.hpp"

int main(void)
{
    int index;
    std::string cmd;
    Contact phonebook[MAX_CONTACTS];
    int t_index;

    t_index = 0;
    index = 0;
    while (1)
    {
        getline(std::cin, cmd);
        if (cmd == "SEARCH")
        {
            if (index > 0)
                showPhonebook(phonebook, index);
            else if (index >= MAX_CONTACTS)
                showPhonebook(phonebook, MAX_CONTACTS);
            else
                std::cout << "Phonebook is empty." << std::endl;
        }
        else if (cmd == "ADD")
        {
            if (index < MAX_CONTACTS)
                phonebook[index++] = addContact();
            else
            {
                if (t_index >= MAX_CONTACTS)
                    t_index = index;
                while (t_index >= MAX_CONTACTS)
                    t_index -= MAX_CONTACTS;
                phonebook[t_index++] = addContact();
            }
        }
        else if (cmd == "EXIT")
            break ;
    }
   return (0);
}
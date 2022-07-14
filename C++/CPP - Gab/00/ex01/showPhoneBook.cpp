#include "contactClass.hpp"

static void searchContact(Contact phonebook[], int n)
{
    int          index;

    std::cout << "Enter the index of a contact: ";
    std::cin >> index;
    std::cout << std::endl;
    if (std::cin.good() && (index >= 0 && index < n))
    {
        std::cout << phonebook[index].getFirstName() << std::endl;
        std::cout << phonebook[index].getLastName() << std::endl;
        std::cout << phonebook[index].getNickName() << std::endl;
        std::cout << phonebook[index].getPhoneNumber() << std::endl;
        std::cout << phonebook[index].getDarkestSecret() << std::endl;
    }
    else
    {
        std::cin.clear();
        std::cout << "Sorry, that index cannot be found. :(" << std::endl;
    }
}

static std::string truncateContact(std::string field)
{
    field = field.erase((FIELD_WIDTH - 1), \
    field.length() - (FIELD_WIDTH - 1));
    field.append(".");
    return (field);
}

void showPhonebook(Contact phonebook[], int index)
{
    std::string     first_name;
    std::string     last_name;
    std::string     nickname;

    std::cout << std::setw(FIELD_WIDTH);
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < index; i++)
    {
        first_name = phonebook[i].getFirstName();
        last_name = phonebook[i].getLastName();
        nickname = phonebook[i].getNickName();

        std::cout << "|" << std::setw(FIELD_WIDTH) << i;
        first_name = (first_name.length() > FIELD_WIDTH) ? \
            truncateContact(first_name) : first_name;
        std::cout << "|" << std::setw(FIELD_WIDTH) << first_name;

        last_name = (last_name.length() > FIELD_WIDTH) ? \
            truncateContact(last_name) : last_name;
        std::cout << "|" << std::setw(FIELD_WIDTH) << last_name;

        nickname = (nickname.length() > FIELD_WIDTH) ? \
            truncateContact(nickname) : nickname;
        std::cout << "|" << std::setw(FIELD_WIDTH) << nickname;
        std::cout << "|" << std::endl;
    }
    searchContact(phonebook, index);
}

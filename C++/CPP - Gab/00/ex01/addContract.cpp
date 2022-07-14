#include "contactClass.hpp"

Contact addContact(void)
{
    Contact contatto;
    std::string read;

    std::cout << "First Name : ";
    std::cin >> read;
    contatto.setFirstName(read);

    std::cout << "Last Name : ";
    std::cin >> read;
    contatto.setLastName(read);

    std::cout << "Nick Name : ";
    std::cin >> read;
    contatto.setNickName(read);

    std::cout << "Phone Number : ";
    std::cin >> read;
    contatto.setPhoneNumber(read);

    std::cout << "Darkest Secret : ";
    std::cin >> read;
    contatto.setDarkestSecret(read);

    std::cout << std::endl << "Salvato con successo!" << std::endl;
    return (contatto);
}
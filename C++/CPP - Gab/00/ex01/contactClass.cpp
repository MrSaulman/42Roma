#include "contactClass.hpp"

Contact::Contact(void)
{
    return ;
}
Contact::~Contact(void)
{
    return ;
}

void    Contact::setFirstName(std::string _firstName)
{
    this->firstName = _firstName;
    return ;
}

void    Contact::setLastName(std::string _lastName)
{
    this->lastName = _lastName;
    return ;
}

void    Contact::setNickName(std::string _nickName)
{
    this->nickName = _nickName;
    return ;
}

void    Contact::setPhoneNumber(std::string _phoneNumber)
{
    this->phoneNumber = _phoneNumber;
    return ;
}

void    Contact::setDarkestSecret(std::string _darkestSecret)
{
    this->darkestSecret = _darkestSecret;
    return ;
}

std::string Contact::getFirstName(void)
{
    return (this->firstName);
}

std::string Contact::getLastName(void)
{
    return (this->lastName);
}

std::string Contact::getNickName(void)
{
    return (this->nickName);
}

std::string Contact::getPhoneNumber(void)
{
    return (this->phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
    return (this->darkestSecret);
}

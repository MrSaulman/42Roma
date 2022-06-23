#include "Contact.hpp"

void Contact::setEmpty()
{
    this->is_empty = true;
}

bool Contact::isEmpty()
{
    if (this->is_empty == true)
        return (1);
    else
        return (0);
}

bool Contact::isLast()
{
    return(this->is_last);
}

void Contact::setLast(bool last)
{
    this->is_last = last;
}

void Contact::setFirstName(std::string f_name)
{
    this->first_name = f_name;
    this->is_empty = false;
}

void Contact::setLastname(std::string l_name)
{
    this->last_name = l_name;
    this->is_empty = false;
}

void Contact::setNick(std::string nick)
{
    this->nickname = nick;
    this->is_empty = false;
}

void Contact::setNumber(std::string number)
{
    this->phone_number = number;
    this->is_empty = false;
}

void Contact::setSecret(std::string secret)
{
    this->secret = secret;
    this->is_empty = false;
}

std::string Contact::getFirstName()
{
    return(this->first_name);
}

std::string Contact::getLastName()
{
    return(this->last_name);
}

std::string Contact::getNick()
{
    return(this->nickname);
}

std::string Contact::getNumber()
{
    return(this->phone_number);
}

std::string Contact::getSecret()
{
    return(this->secret);
}
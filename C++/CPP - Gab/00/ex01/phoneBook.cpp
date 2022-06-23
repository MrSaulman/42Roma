#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <stdlib.h>

int strLen(std::string str);
std::string formatPar(std::string par);
void writeFormat(int index, std::string first_name, std::string last_name, std::string nickname);

void PhoneBook::init()
{
    for(int i = 0; i <= 7; i++)
        this->contacts[i].setEmpty();
}


void PhoneBook::SearchContact(int index)
{
    if (this->contacts[index].isEmpty() == true)
    {
        std::cout << "contact "<< index << " is empty" << std::endl;
        return;
    }
    std::cout << this->contacts[index].getFirstName() << std::endl;
    std::cout << this->contacts[index].getLastName() << std::endl;
    std::cout << this->contacts[index].getNick() << std::endl;
    std::cout << this->contacts[index].getNumber() << std::endl;
    std::cout << this->contacts[index].getSecret() << std::endl;
}

void PhoneBook::displayContacts()
{
    int i = 0;

    while (this->contacts[i].isEmpty() != true && i <= 7)
    {
        writeFormat(i, this->contacts[i].getFirstName(), this->contacts[i].getLastName(), this->contacts[i].getNick());
        i++;
    }
}

int PhoneBook::searchAddIndex()
{
    int i = 0;

    while (i <= 7)
    {
        if(this->contacts[i].isEmpty() == true)
        {
            this->contacts[i].setLast(false);
            return (i);
        }
        i++;
    }
    i = 0;
    while (i <= 7)
    {
        if(this->contacts[i].isLast() == true)
        {
            this->contacts[i].setLast(false);
            i++;
            this->contacts[i].setLast(true);
            if(i == 8)
                break;
            return (i);
        }
        i++;
    }
    i = 0;
    this->contacts[i].setLast(true);
    return(0);
}

void PhoneBook::addContact(int index, std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string secret)
{
    this->contacts[index].setFirstName(first_name);
    this->contacts[index].setLastname(last_name);
    this->contacts[index].setNick(nickname);
    this->contacts[index].setNumber(phone_number);
    this->contacts[index].setSecret(secret);
}

void writeFormat(int index, std::string first_name, std::string last_name, std::string nickname)
{
    std::string line_par, u_char;
    char c_index = index + 48;
    u_char[0] = c_index;
    std::cout << formatPar(u_char) << '|';
    std::cout << formatPar(first_name) << '|';
    std::cout << formatPar(last_name) << '|';
    std::cout << formatPar(nickname) << std::endl;
}

std::string formatPar(std::string par)
{
    char line[11];
    int i = 0, dif = 0, count = 0;

    count = strLen(par);
    if (count >= 9) //?? non dovrebbe essere > 10?
    {
        par[9] = '.';
        while (i <= 9)
        {
            line[i] = par[i];
            i++;
        }
    }
    else
    {
        dif = 9 - count;
        while (i <= dif)
        {
            line[i] = ' ';
            i++; 
        }
        while (i <= count + dif) // questo me sa che è sempre 9?
        {
            line[i] = par[i - dif - 1];
            i++;
        }
    }
    line[i] = '\0';
    return(line);
}

int strLen(std::string str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

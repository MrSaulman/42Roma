#include "Karen.hpp"

void    Karen::complain(std::string level)
{
    std::string message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;

	for(i = 0; i <= 4; i++)
		if(level == message[i])
			break;
    switch (i)
    {
    case 0:
        this->Karen::debug();
        this->Karen::info();
        this->Karen::warning();
        this->Karen::error();
        break;
    case 1:
        this->Karen::info();
        this->Karen::warning();
        this->Karen::error();
        break;
    case 2:
        this->Karen::warning();
        this->Karen::error();
        break;
    case 3:
        this->Karen::error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}

Karen::~Karen() {}

Karen::Karen() {}

void Karen::debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Karen::info(void)
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Karen::warning(void)
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Karen::error(void)
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
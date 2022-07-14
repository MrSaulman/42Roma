#include "Karen.hpp"

Karen::Karen()
{
}

Karen::~Karen()
{
}

void Karen::complain( std::string level )
{
	std::string s[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	for(i = 0; i <= 4; i++)
		if(level == s[i])
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

void    Karen::debug(void)
{   
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love to get extra bacon "
 << "for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void    Karen::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra" <<
"bacon cost more money. You don’t put enough! If you did I would not have to ask"
<< "for it!" << std::endl;
}

void    Karen::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been \
coming here for years and you just started working here last month." << std::endl;
}

void    Karen::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

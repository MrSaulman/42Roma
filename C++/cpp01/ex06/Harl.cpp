/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:05:43 by asalvemi          #+#    #+#             */
/*   Updated: 2022/07/14 18:05:44 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::complain(std::string level)
{
    std::string message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;

	for(i = 0; i <= 4; i++)
		if(level == message[i])
			break;
    switch (i)
    {
    case 0:
        this->Harl::debug();
        this->Harl::info();
        this->Harl::warning();
        this->Harl::error();
        break;
    case 1:
        this->Harl::info();
        this->Harl::warning();
        this->Harl::error();
        break;
    case 2:
        this->Harl::warning();
        this->Harl::error();
        break;
    case 3:
        this->Harl::error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}

Harl::~Harl() {}

Harl::Harl() {}

void Harl::debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
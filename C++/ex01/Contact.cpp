/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:55:23 by asalvemi          #+#    #+#             */
/*   Updated: 2022/06/23 14:43:05 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::fields[7] = {
    "Firstname",
    "LastName",
    "Nickname",
    "Address",
    "Email",
    "Phone",
    "Birthday"
};

Contact::Contact() {
    for (int i = Firstname; i <= Birthday; i++)
        this->informations[i] = std::string();
}

Contact::~Contact() {}

bool Contact::set_information(int index)
{
    this->index = index;
    for (int i = Firstname; i <= Birthday; i++)
    {
        
    }
}
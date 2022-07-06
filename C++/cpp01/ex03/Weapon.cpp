/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:00:38 by asalvemi          #+#    #+#             */
/*   Updated: 2022/07/06 19:00:39 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string weapon)
{
    this->type = weapon;
}

const std::string &Weapon::getType()
{
    return(this->type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

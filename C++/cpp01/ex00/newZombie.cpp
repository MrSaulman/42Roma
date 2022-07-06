/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:58:56 by asalvemi          #+#    #+#             */
/*   Updated: 2022/07/06 18:58:57 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
# include <iostream>

Zombie* newZombie(std::string name)
{
    Zombie *new_z;

    new_z = new Zombie(name);
    return (new_z);
}
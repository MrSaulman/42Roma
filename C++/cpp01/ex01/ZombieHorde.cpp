/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:59:52 by asalvemi          #+#    #+#             */
/*   Updated: 2022/07/06 18:59:53 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
# include <iostream>

Zombie*    zombieHorde( int n, std::string name )
{
    Zombie *horde;

    horde = new Zombie[n];

    for (int i = 0; i < n; i++)
    {
        horde[i].setName(name);
    }
    return (horde);
}

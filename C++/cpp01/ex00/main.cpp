/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:58:48 by asalvemi          #+#    #+#             */
/*   Updated: 2022/07/06 18:58:49 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombie_pazzo;

    zombie_pazzo = newZombie("zombie_pazzo1");
    zombie_pazzo->announce();
    randomChump("ziobulubu");
    zombie_pazzo->~Zombie();
    return (0);
}
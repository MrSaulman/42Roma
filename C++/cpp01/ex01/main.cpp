/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:59:33 by asalvemi          #+#    #+#             */
/*   Updated: 2022/07/06 18:59:35 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *horde;
    int n = 7;

    horde = zombieHorde(n, "hooooorde_soldier");
    for(int i = 0; i < n; i++)
        horde[i].announce();
    delete[] horde;
    return (0);
}

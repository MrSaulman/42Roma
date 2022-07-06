/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:00:29 by asalvemi          #+#    #+#             */
/*   Updated: 2022/07/06 19:00:29 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"
# include <string>

class HumanB
{
    public:
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        void attack();

    private:
        Weapon *weapon;
        std::string name;
};

#endif

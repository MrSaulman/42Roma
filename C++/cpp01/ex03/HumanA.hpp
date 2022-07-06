/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:00:22 by asalvemi          #+#    #+#             */
/*   Updated: 2022/07/06 19:00:23 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"
# include <string>

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        void attack();

    private:
        Weapon &weapon;
        std::string name;
};

#endif

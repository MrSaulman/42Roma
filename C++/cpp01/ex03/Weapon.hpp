/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:00:41 by asalvemi          #+#    #+#             */
/*   Updated: 2022/07/06 19:00:53 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class Weapon
{
    public:
        Weapon();
        Weapon(std::string weapon);
        const std::string &getType();
        void setType(std::string type);

    private:
        std::string type;
};

#endif

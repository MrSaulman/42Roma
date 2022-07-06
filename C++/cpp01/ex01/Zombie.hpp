/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:59:49 by asalvemi          #+#    #+#             */
/*   Updated: 2022/07/06 18:59:49 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        Zombie(std::string name);
        void setName(std::string name);
        void announce(void);

    private:
        std::string name;
};

Zombie*    zombieHorde( int n, std::string name );

#endif

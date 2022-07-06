/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:59:23 by asalvemi          #+#    #+#             */
/*   Updated: 2022/07/06 18:59:24 by asalvemi         ###   ########.fr       */
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
        void announce(void);

    private:
        std::string name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:05:32 by asalvemi          #+#    #+#             */
/*   Updated: 2022/07/14 18:05:33 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <string>
#include <iostream>

class Harl
{
    public:
        Harl();
        ~Harl();
        void    complain(std::string level);

    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void ); 
        void    (Harl::*_level[4])(void);
};

#endif
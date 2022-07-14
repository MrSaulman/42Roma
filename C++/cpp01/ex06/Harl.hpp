/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:05:46 by asalvemi          #+#    #+#             */
/*   Updated: 2022/07/14 18:05:47 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_H
# define KAREN_H

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
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:38:33 by asalvemi          #+#    #+#             */
/*   Updated: 2022/06/16 17:03:27 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "contact.hpp"

class Phonebook {
    private:
        Contact contacts[8];
        int     amount;
    public:
        Phonebook();
        virtual ~Phonebook();

        
}

#endif
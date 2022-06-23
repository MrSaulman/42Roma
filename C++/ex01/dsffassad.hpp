/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:38:33 by asalvemi          #+#    #+#             */
/*   Updated: 2022/06/22 18:54:57 by asalvemi         ###   ########.fr       */
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

        void    show_startup();
        void    add_contact();
        void    search_contact();
        void    show_search_header();
        
};

#endif
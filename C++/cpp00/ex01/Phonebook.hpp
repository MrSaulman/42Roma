/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:38:33 by asalvemi          #+#    #+#             */
/*   Updated: 2022/06/27 17:29:31 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    public:
        void init();
        void displayContacts();
        void SearchContact(int index);
        int searchAddIndex();    
        void addContact(int index, std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string secret);

    private:
        Contact contacts[8];
};

#endif
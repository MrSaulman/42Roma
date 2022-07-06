/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:40:38 by asalvemi          #+#    #+#             */
/*   Updated: 2022/06/27 17:23:23 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
    public:
        bool isEmpty();
        bool isLast();
        void setLast(bool last);       
        void setFirstName(std::string f_name);
        void setLastname(std::string l_name);
        void setNick(std::string nick);
        void setNumber(std::string number);
        void setSecret(std::string secret);
        void setEmpty();
        std::string getFirstName();
        std::string getLastName();
        std::string getNick();
        std::string getNumber();
        std::string getSecret();

    private:
        bool is_last;
        bool is_empty;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string secret;
};

#endif

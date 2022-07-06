/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:01:42 by asalvemi          #+#    #+#             */
/*   Updated: 2022/06/13 16:37:41 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

int main(int argc, char const *argv[])
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i++)
        {
            std::string str((argv[i]));
            for (size_t j = 0; j < str.length(); j++)
                std::cout << (char)std::toupper(str[j]);
        }
        std::cout << std::endl;
    }
    return (0);
}

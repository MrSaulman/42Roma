/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:51:08 by asalvemi          #+#    #+#             */
/*   Updated: 2022/02/21 21:50:41 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int ascii[255] = {0};
    int i = 2, j = 0;
    if (argc == 3)
    {
        while (i > 0)
        {
            j = 0;
            while (argv[i][j])
            {
                if (i == 2 && ascii[(int)argv[i][j]] == 0)
                {
                    ascii[(int)argv[i][j]] = 1;
                }
                else if (i == 1 && ascii[(int)argv[i][j]] == 1)
                {
                    write(1, &argv[i][j], 1);
                    ascii[(int)argv[i][j]] = 2;
                }
                j++;
            }
            i--;
        }
    }
    write(1, "\n", 1);
    return (0);
}

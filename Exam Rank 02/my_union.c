/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:33:43 by asalvemi          #+#    #+#             */
/*   Updated: 2022/02/21 18:47:39 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int j;
	int ascii[255];

	if (argc != 3)
	{
		return (write(1, "\n", 1));
	}

	i = 1;
	while (i < 3) {
		j = 0;
		while (argv[i][j]) {
			if (!ascii[(int)argv[i][j]]) {
				ascii[(int)argv[i][j]] = 1;
				write(1, &argv[i][j], 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return 0;
}


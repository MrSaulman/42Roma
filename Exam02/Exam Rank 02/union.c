/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:32:25 by ffrau             #+#    #+#             */
/*   Updated: 2022/02/21 18:22:38 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	ascii[255];
	int	i;
	int	j;

	if(argc != 3)
		return (write(1, "\n", 1));

	i = 1;
	while(i < 3)
	{
		j = 0;
		while(argv[i][j])
		{
			if(!ascii[(int)argv[i][j]])
			{
				ascii[(int)argv[i][j]] = 1;
				write(1, &argv[i][j], 1);
			}
			j++;
		}
		i++;
	}
	return (write(1, "\n", 1));
}

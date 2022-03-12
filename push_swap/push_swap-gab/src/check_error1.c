/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:34:45 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/10/14 10:59:10 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_empty(char *argv)
{
	if (!ft_strcmp("", argv) || !ft_strcmp(" ", argv))
	{
		exit(0);
	}
	else
		return (1);
}

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atol(argv[i]) > MAX_INT || ft_atol(argv[i]) < MIN_INT
			|| check_duplicate(argc, argv) == 1
			|| check_integers(argc, argv) == 1)
			return (ft_error());
		i++;
	}		
	return (0);
}

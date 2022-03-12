/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:25:32 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/10/14 10:59:06 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_arg_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit((int)str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_integers(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_arg_number(argv[i]) == 0)
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_duplicate_arr(int *arr, int argc)
{
	int	*tmp;
	int	i;
	int	j;
	int	k;

	tmp = arr;
	i = 0;
	j = 0;
	k = 0;
	while (i < (argc - 1))
	{
		while (j < (argc - 1))
		{
			if (arr[i] == tmp[j])
				k++;
			j++;
		}
		j = 0;
		i++;
	}
	if (k != 0 && k != 1 && k != (argc - 1))
		return (1);
	else
		return (0);
}

int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;
	int	*arr;

	i = 1;
	j = 0;
	arr = (int *)ft_calloc((argc - 1), sizeof(int));
	while (i < argc)
		arr[j++] = ft_atoi(argv[i++]);
	i = 0;
	i = check_duplicate_arr(arr, argc);
	free(arr);
	if (i > 0)
		return (1);
	else
		return (0);
}

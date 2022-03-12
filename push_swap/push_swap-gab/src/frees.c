/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:04:37 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/10/14 10:59:17 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stacks(t_Node **StackA, t_Node **StackB)
{
	while (*StackA)
	{
		free(*StackA);
		*StackA = (*StackA)->next;
	}
	while (*StackB)
	{
		free(*StackB);
		*StackB = (*StackB)->next;
	}
}

void	null_stack(t_Node **StackA, t_Node **StackB)
{
	(*StackA)->next = NULL;
	(*StackB)->next = NULL;
}

void	free_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	argv[0] = malloc(sizeof(4));
	while (i < argc)
		free(argv[i++]);
	free(argv);
}

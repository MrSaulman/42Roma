/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:48:18 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/10/14 10:58:55 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_hundred(t_Node **StackA, t_Node **StackB)
{
	int		chunk;
	int		pos;
	int		i;

	chunk = 0;
	i = 1;
	while (*StackA)
	{
		chunk = chunk + 17;
		while (i <= chunk)
		{
			if (!(*StackA))
				break ;
			pos = compare_smallest_pos(StackA, chunk);
			ra_rra_pos(StackA, pos);
			push_node(StackB, StackA, 2);
			i++;
		}
		set_index(StackB);
	}
	pushback_all(StackA, StackB);
}

void	sort_twofifty(t_Node **StackA, t_Node **StackB)
{
	int		chunk;
	int		pos;
	int		i;

	chunk = 0;
	i = 1;
	while (*StackA)
	{
		chunk = chunk + 30;
		while (i <= chunk)
		{
			if (!(*StackA))
				break ;
			pos = compare_smallest_pos(StackA, chunk);
			ra_rra_pos(StackA, pos);
			push_node(StackB, StackA, 2);
			i++;
		}
		set_index(StackB);
	}
	pushback_all(StackA, StackB);
}

void	sort_fivehundred(t_Node **StackA, t_Node **StackB)
{
	int		chunk;
	int		pos;
	int		i;

	chunk = 0;
	i = 1;
	while (*StackA)
	{
		chunk = chunk + 44;
		while (i <= chunk)
		{
			if (!(*StackA))
				break ;
			pos = compare_smallest_pos(StackA, chunk);
			ra_rra_pos(StackA, pos);
			push_node(StackB, StackA, 2);
			i++;
		}
		set_index(StackB);
	}
	pushback_all(StackA, StackB);
}

void	sort_plus(t_Node **StackA, t_Node **StackB)
{
	int		chunk;
	int		pos;
	int		i;

	chunk = 0;
	i = 1;
	while (*StackA)
	{
		chunk = chunk + 45;
		while (i <= chunk)
		{
			if (!(*StackA))
				break ;
			pos = compare_smallest_pos(StackA, chunk);
			ra_rra_pos(StackA, pos);
			push_node(StackB, StackA, 2);
			i++;
		}
		set_index(StackB);
	}
	pushback_all(StackA, StackB);
}

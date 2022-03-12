/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:48:40 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/10/14 10:58:59 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_two(t_Node **StackA)
{
	t_Node	*tmp;

	tmp = *StackA;
	if (tmp->data > tmp->next->data)
		swap_nodes(StackA, 1);
}

void	sort_three(t_Node **StackA)
{
	int		one;
	int		two;
	int		three;
	t_Node	*tmp;

	tmp = *StackA;
	one = tmp->data;
	two = tmp->next->data;
	three = tmp->next->next->data;
	if (one > two && two < three && three > one)
		swap_nodes(StackA, 1);
	else if (one > two && two > three && three < one)
	{
		swap_nodes(StackA, 1);
		reverse_rotate(StackA, 1);
	}
	else if (one > two && two < three && three < one)
		rotate_stack(StackA, 1);
	else if (one < two && two > three && three > one)
	{
		swap_nodes(StackA, 1);
		rotate_stack(StackA, 1);
	}
	else if (one < two && two > three && three < one)
		reverse_rotate(StackA, 1);
}

void	sort_five(t_Node **StackA, t_Node **StackB)
{
	int	size;
	int	pos;
	int	i;

	i = 0;
	size = stack_len(StackA);
	while (i < (size - 3))
	{
		pos = smallest_pos(StackA);
		ra_rra_pos(StackA, pos);
		push_node(StackB, StackA, 2);
		i++;
	}
	sort_three(StackA);
	while (i > 0)
	{
		push_node(StackA, StackB, 1);
		i--;
	}
}

void	sort_twenty(t_Node **StackA, t_Node **StackB)
{
	int		chunk;
	int		pos;
	int		i;

	chunk = 0;
	i = 1;
	while (*StackA)
	{
		chunk = chunk + 5;
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

void	sort_fifty(t_Node **StackA, t_Node **StackB)
{
	int		chunk;
	int		pos;
	int		i;

	chunk = 0;
	i = 1;
	while (*StackA)
	{
		chunk = chunk + 13;
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

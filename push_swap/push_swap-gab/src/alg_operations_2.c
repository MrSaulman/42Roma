/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_operations_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:46:44 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/10/14 10:58:26 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	begin_pos(t_Node **Stack, int chunk)
{
	t_Node	*begin;
	int		pos_begin;
	int		i;

	i = 0;
	begin = *Stack;
	pos_begin = 0;
	while (begin)
	{
		if (begin->index <= chunk)
		{
			pos_begin = i;
			break ;
		}
		begin = begin->next;
		i++;
	}
	return (pos_begin);
}

t_Node	*reset_end(t_Node **Stack, int len)
{
	t_Node	*end;
	int		k;

	k = 0;
	end = *Stack;
	while (k < len)
	{
		end = end->next;
		k++;
	}
	return (end);
}

void	init_arr(int *arr, t_Node **Stack, int chunk)
{
	arr[0] = stack_len(Stack);
	arr[4] = 0;
	arr[3] = begin_pos(Stack, chunk);
	arr[1] = 0;
	arr[2] = stack_len(Stack) - 1;
}

int	compare_smallest_pos(t_Node **Stack, int chunk)
{
	t_Node	*end;
	int		arr[5];

	init_arr(arr, Stack, chunk);
	end = *Stack;
	while (arr[2] > 0)
	{
		arr[1] = 0;
		while (arr[1] < arr[2])
		{
			end = end->next;
			arr[1]++;
		}
		if (end->index <= chunk)
		{
			arr[4] = arr[0] - 1;
			break ;
		}
		end = *Stack;
		arr[0]--;
		arr[2]--;
	}
	if (arr[3] <= (stack_len(Stack) - arr[4]))
		return (arr[3]);
	return (arr[4]);
}

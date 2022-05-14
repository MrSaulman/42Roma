/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:45:46 by ldalle-a          #+#    #+#             */
/*   Updated: 2022/04/08 19:05:22 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_len(t_Node **Stack)
{
	int		i;
	t_Node	*tmp;

	i = 0;
	tmp = *Stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	create_stack(int argc, char **argv, t_Node **Stack)
{
	int		i;
	t_Node	*tmp;

	tmp = *Stack;
	i = 1;
	while (argc-- > 1)
	{
		(*Stack)->data = ft_atoi(argv[i++]);
		(*Stack)->next = (t_Node *)malloc(sizeof(t_Node));
		(*Stack) = (*Stack)->next;
	}
	(*Stack)->next = NULL;
	*Stack = tmp;
	delete_last_node(Stack);
}

int	list_sorted(t_Node **Stack)
{
	t_Node	*tmp;

	tmp = *Stack;
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	set_index(t_Node **Stack)
{
	t_Node	*outer;
	t_Node	*inner;
	int		index;

	outer = *Stack;
	while (outer)
	{
		index = stack_len(Stack);
		outer->index = index;
		inner = *Stack;
		while (inner)
		{
			if (outer->data < inner->data)
				outer->index--;
			inner = inner->next;
		}
		outer = outer->next;
	}
}

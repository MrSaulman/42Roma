/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:30:26 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/10/14 11:15:23 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	delete_last_node(t_Node **Stack)
{
	t_Node	*to_del_last;
	t_Node	*pre_node;

	if (*Stack == NULL)
		printf(" There is no element in the list.");
	else
	{
		to_del_last = *Stack;
		pre_node = *Stack;
		while (to_del_last->next != NULL)
		{
			pre_node = to_del_last;
			to_del_last = to_del_last->next;
		}
		if (to_del_last == *Stack)
			*Stack = NULL;
		else
		{
			pre_node->next = NULL;
		}
		free(to_del_last);
	}
}

void	swap_nodes(t_Node **Stack, int i)
{
	t_Node	*tmp;

	if (!*Stack)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	tmp = *Stack;
	tmp = tmp->next;
	(*Stack)->next = tmp->next;
	tmp->next = *Stack;
	*Stack = tmp;
	if (i == 1)
		write(1, "sa\n", 3);
	else if (i == 2)
		write(1, "sb\n", 3);
}

void	reverse_rotate(t_Node **Stack, int i)
{
	t_Node	*current;
	t_Node	*kth_node;

	if (!*Stack)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	current = *Stack;
	while (current->next != NULL)
		current = current->next;
	kth_node = *Stack;
	while (kth_node->next != current)
		kth_node = kth_node->next;
	current->next = *Stack;
	*Stack = current;
	kth_node->next = NULL;
	if (i == 1)
		write(1, "rra\n", 4);
	else if (i == 2)
		write(1, "rrb\n", 4);
}

void	rotate_stack(t_Node **Stack, int i)
{
	t_Node	*current;
	t_Node	*kth_node;

	if (!*Stack)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	current = *Stack;
	if (current == NULL)
		return ;
	kth_node = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *Stack;
	*Stack = kth_node->next;
	kth_node->next = NULL;
	if (i == 1)
		write(1, "ra\n", 3);
	else if (i == 2)
		write(1, "rb\n", 3);
}

void	swap_data(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

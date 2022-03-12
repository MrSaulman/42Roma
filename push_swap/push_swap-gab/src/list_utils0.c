/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:28:49 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/10/14 11:14:19 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print(t_Node *first)
{
	t_Node	*current_node;

	current_node = first;
	while (current_node != NULL)
	{
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
	printf("\n");
}

t_Node	*ft_lstnew(int data)
{
	t_Node	*new;

	new = (t_Node *)malloc(sizeof(t_Node));
	if (!new)
		return (0);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_Node **lst, t_Node *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void	delete_first_node(t_Node **Stack)
{
	t_Node	*to_delete;

	if (Stack == NULL)
		return ;
	else
	{
		to_delete = *Stack;
		*Stack = (*Stack)->next;
		free(to_delete);
	}
}

void	push_node(t_Node **dest, t_Node **source, int i)
{
	t_Node	*new;

	if (!*source)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	new = ft_lstnew((*source)->data);
	ft_lstadd_front(dest, new);
	delete_first_node(source);
	if (i == 1)
		write(1, "pa\n", 3);
	else if (i == 2)
		write(1, "pb\n", 3);
}

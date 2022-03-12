/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:04:07 by gcrocett          #+#    #+#             */
/*   Updated: 2021/10/14 11:04:11 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_str_sim(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
}

void	double_op(t_Node **StackA, t_Node **StackB, char *command)
{
	if (ft_str_sim(command, "ss"))
	{
		swap_nodes(StackA, 3);
		swap_nodes(StackB, 3);
	}
	else if (ft_str_sim(command, "rr"))
	{
		rotate_stack(StackA, 3);
		rotate_stack(StackB, 3);
	}
	else if (ft_str_sim(command, "rrr"))
	{
		reverse_rotate(StackA, 3);
		reverse_rotate(StackB, 3);
	}
}

void	quit_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	operate(t_Node **StackA, t_Node **StackB, char *command)
{
	if (ft_str_sim(command, "sa"))
		swap_nodes(StackA, 3);
	else if (ft_str_sim(command, "sb"))
		swap_nodes(StackB, 3);
	else if (ft_str_sim(command, "ss"))
		double_op(StackA, StackB, command);
	else if (ft_str_sim(command, "pa"))
		push_node(StackA, StackB, 3);
	else if (ft_str_sim(command, "pb"))
		push_node(StackB, StackA, 3);
	else if (ft_str_sim(command, "ra"))
		rotate_stack(StackA, 3);
	else if (ft_str_sim(command, "rb"))
		rotate_stack(StackB, 3);
	else if (ft_str_sim(command, "rr"))
		double_op(StackA, StackB, command);
	else if (ft_str_sim(command, "rra"))
		reverse_rotate(StackA, 3);
	else if (ft_str_sim(command, "rrb"))
		reverse_rotate(StackB, 3);
	else if (ft_str_sim(command, "rrr"))
		double_op(StackA, StackB, command);
	else
		quit_error();
}

void	do_operations(t_Node **StackA, t_Node **StackB)
{
	char	*command;

	while (get_next_line(0, &command))
	{
		operate(StackA, StackB, command);
		free(command);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inizialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:57:58 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/10/14 11:13:29 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	inizialize_stack(int argc, char **argv, int i)
{
	t_Node	*stack_a;
	t_Node	*stack_b;

	stack_a = (t_Node *) malloc(sizeof(t_Node));
	stack_b = (t_Node *) malloc(sizeof(t_Node));
	null_stack(&stack_a, &stack_b);
	delete_first_node(&stack_b);
	create_stack(argc, argv, &stack_a);
	if (i == 0 && list_sorted(&stack_a) == 0 && (!stack_b))
	{
		free_stacks(&stack_a, &stack_b);
		exit(0);
	}
	set_index(&stack_a);
	if (i == 0)
		parse_alg(&stack_a, &stack_b);
	else if (i == 1)
	{
		do_operations(&stack_a, &stack_b);
		if (list_sorted(&stack_a) == 0 && (!stack_b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_stacks(&stack_a, &stack_b);
}

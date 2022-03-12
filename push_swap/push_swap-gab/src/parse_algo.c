/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:05:57 by gcrocett          #+#    #+#             */
/*   Updated: 2021/10/14 11:06:00 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	parse_alg(t_Node **StackA, t_Node **StackB)
{
	int	size;

	size = stack_len(StackA);
	if (size == 2)
		sort_two(StackA);
	else if (size == 3)
		sort_three(StackA);
	else if (size == 4 || size == 5)
		sort_five(StackA, StackB);
	else if (size > 5 && size < 21)
		sort_twenty(StackA, StackB);
	else if (size >= 21 && size <= 50)
		sort_fifty(StackA, StackB);
	else if (size > 50 && size <= 100)
		sort_hundred(StackA, StackB);
	else if (size > 100 && size <= 250)
		sort_twofifty(StackA, StackB);
	else if (size > 250 && size <= 500)
		sort_fivehundred(StackA, StackB);
	else if (size > 500)
		sort_plus(StackA, StackB);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:19:12 by asalvemi          #+#    #+#             */
/*   Updated: 2021/03/15 19:46:24 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	if (lst)
	{
		temp = (*lst);
		if (temp == NULL)
			(*lst) = new;
		else
		{
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
	}
}

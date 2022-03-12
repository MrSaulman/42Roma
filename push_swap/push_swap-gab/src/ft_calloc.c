/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:04:23 by gcrocett          #+#    #+#             */
/*   Updated: 2021/10/14 11:09:56 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		((unsigned char *)str)[count] = c;
		count++;
	}
	return (str);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t		size_tot;
	void		*dst;

	size_tot = size * nitems;
	dst = malloc(size_tot);
	if (!dst)
		return (0);
	ft_memset(dst, 0, size_tot);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:16:27 by asalvemi          #+#    #+#             */
/*   Updated: 2021/01/12 14:16:28 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	size_t			i;

	cs1 = (unsigned char *)(s1);
	cs2 = (unsigned char *)(s2);
	i = 0;
	while (i < n && *(cs1 + i) == *(cs2 + i))
		i++;
	if (i == n)
		return (0);
	return (*(cs1 + i) - *(cs2 + i));
}

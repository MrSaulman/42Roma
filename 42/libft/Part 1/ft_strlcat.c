/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:16:54 by asalvemi          #+#    #+#             */
/*   Updated: 2021/01/12 14:16:55 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t d;
	size_t s;
	size_t len;

	i = 0;
	d = 0;
	s = 0;
	len = 0;
	if (size > 0)
	{
		while (dest[d])
			d++;
		while (src[s])
			s++;
		if (size <= d)
			len = s + size;
		else
			len = s + d;
		while (src[i] && d < size - 1)
			dest[d++] = src[i++];
		dest[d] = '\0';
	}
	return (len);
}

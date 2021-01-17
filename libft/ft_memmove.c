/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:16:05 by asalvemi          #+#    #+#             */
/*   Updated: 2021/01/12 14:16:06 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (unsigned char*)dest;
	ptr2 = (unsigned char*)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (ptr2 < ptr1)
		while (++i <= len)
			ptr1[len - i] = ptr2[len - i];
	else
		while (len-- > 0)
			*(ptr1++) = *(ptr2++);
	return (dest);
}

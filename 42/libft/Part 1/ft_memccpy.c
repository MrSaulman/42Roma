/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:15:46 by asalvemi          #+#    #+#             */
/*   Updated: 2021/01/12 14:15:48 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
  unsigned char *csrc;
  unsigned char *cdest;
  int i;

  csrc = (unsigned char *)src;
  cdest = (unsigned char *)dest;
  i = 0;

    while (i < n)
    {
      cdest[i] = csrc[i];
      i++;
      if (csrc[i] == (unsigned char)c)
        return (dest + i + 1);
    }
    return (NULL);
}

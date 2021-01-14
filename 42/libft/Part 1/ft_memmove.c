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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
  unsigned char *csrc;
  unsigned char *cdest;
  int i;

  csrc = (unsigned char *)src;
  cdest = (unsigned char *)dest;
  if (csrc == cdest || n == 0)
    return dest;
  if (cdest > csrc)
  {
      i = n - 1;
      while (i >= 0)
    {
        cdest[i] = csrc[i];
        i--;
    }
    return dest;
  }
  if (cdest < csrc)
  {
      i = 0;
      while (i < n)
      {
          cdest[i] = csrc[i];
          i++;
      }
      return dest;
  }
  return dest;
}

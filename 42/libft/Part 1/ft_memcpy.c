/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:15:22 by asalvemi          #+#    #+#             */
/*   Updated: 2021/01/12 14:15:24 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
  }
  return (cdest);
}

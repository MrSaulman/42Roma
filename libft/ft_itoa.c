/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:53:11 by asalvemi          #+#    #+#             */
/*   Updated: 2021/01/18 15:53:12 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_len_int(n);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len + 1] = '\0';
	while (len-- > 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

int		ft_len_int(int n)
{
	int		len;

	len = 0;
	while (n >= 1 || n <= -1)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

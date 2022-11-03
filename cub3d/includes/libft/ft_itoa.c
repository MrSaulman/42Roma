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
	int		sign;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (n < 0) ? -1 : 1;
	len = (n < 0) ? ft_len_int(n) + 1 : ft_len_int(n);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	n *= sign;
	while (len-- > 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

int		ft_len_int(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n >= 1 || n <= -1)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

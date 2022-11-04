/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarbant <gbarbant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:53:11 by asalvemi          #+#    #+#             */
/*   Updated: 2022/11/04 12:29:45 by gbarbant         ###   ########.fr       */
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
	sign = ft_sign(n);
	len = ft_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
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

int	ft_len_int(int n)
{
	int	len;

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

int	ft_sign(int n)
{
	int	sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	return (sign);
}

int	ft_len(int n)
{
	int	len;

	if (n < 0)
		len = ft_len_int(n) + 1;
	else
		len = ft_len_int(n);
	return (len);
}

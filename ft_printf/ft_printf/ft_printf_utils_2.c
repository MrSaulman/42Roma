/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:13:05 by asalvemi          #+#    #+#             */
/*   Updated: 2021/03/21 18:29:12 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_str(char *str, t_flags *flags)
{
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(str);
	i = 0;
	if ((flags->precision == 1) && flags->precision_l < (int)len)
		len = flags->precision_l;
	if (flags->width > 0 && flags->minus != 1)
		ft_width(flags->width, len, flags);
	if (flags->zero > 0 && flags->minus != 1)
		flags->printed += ft_zero(len, flags->zero);
	while (i < len && len != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	if (flags->zero > 0 && flags->minus == 1)
		ft_width(flags->zero, len, flags);
	if (flags->width > 0 && flags->minus == 1)
		ft_width(flags->width, len, flags);
	return (i);
}

int     ft_check_segfault(const char *s)
{
	int     i;
	int     ok;

	i = 0;
	ok = 0;
	while(s[i])
	{
		if (ft_strchr(CONVERSIONS, s[i]))
		{
			ok = 1;
		}
		i++;
	}
	return (ok);
}

int     ft_neg_star(int num, t_flags *flags)
{
	if (flags->precision == 1)
	{
		flags->precision = 0;
		return(0);
	}
	flags->minus = 1;
	return (num * -1);
}
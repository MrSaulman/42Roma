/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:13:10 by asalvemi          #+#    #+#             */
/*   Updated: 2021/03/27 15:51:28 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->precision_l = 0;
	flags->width = 0;
	flags->negative = 0;
}

void	ft_get_width(const char *s, int *i, t_flags *d, va_list ap)
{
	if (s[*i] == '*')
	{
		d->width = va_arg(ap, int);
		if (d->width < 0)
		{
			d->width *= -1;
			d->minus = 1;
		}
		i += 1;
	}
	else
	{
		d->width = ft_atoi(s + *i);
		while (ft_isdigit(s[*i]))
			*i += 1;
		*i -= 1;
	}
}

void	ft_width(int width, int str_length, t_flags *flags)
{
	int		i;
	int		spaces;

	if (str_length < width)
	{
		i = 0;
		if (str_length == 0)
			spaces = width;
		else
			spaces = (width - str_length);
		while (i < spaces)
		{
			flags -> printed += write(1, " ", 1);
			i++;
		}
	}
}

int		ft_control_star(const char *s, int *i, va_list ap, t_flags *flags)
{
	int num;

	num = 0;
	*i += 1;
	if (ft_strchr("1234567890", s[*i]))
	{
		num = ft_atoi(s + *i);
		while (ft_isdigit(s[*i]))
			*i += 1;
	}
	else if ('*'== s[*i])
	{
		num = va_arg(ap, int);
		if (num < 0)
			num = ft_neg_star(num, flags);
	}
	else
		*i -= 1;
	return (num);
}

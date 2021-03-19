/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:12:58 by asalvemi          #+#    #+#             */
/*   Updated: 2021/03/19 16:54:01 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_total_digits(t_flags *flags, int digits)
{
	int				diff;

	diff = 0;
	if (flags->precision == 1 && flags->precision > digits)
		diff = flags->precision_l - digits;
	else if (flags->zero > digits && flags->precision == 0 && flags ->minus != 1)
		diff = flags->zero - digits;
	if (flags->negative == 1 &&
	(diff > 0 || (flags->minus == 1 && flags->zero == 0)))
		diff += 1;
	return (digits + diff);
}

void	ft_putnbr_flags(int n, t_flags *flags)
{
	char			c;

	if (n <= 2147483647 && n > -2147483648 &&
	(flags->precision != 1 || flags->precision == 1 && flags->precision_l != 0))
	{
		if (flags->negative == 1 && flags->zero == 0 && flags->precision_l == 0)
		{
			flags->printed += write(1, "-", 1);
			flags-> negative = 0;
		}
		if (n > 9)
		{
			ft_putnbr_flags(n / 10, flags);
		}
		c = (n % 10) + '0';
		flags->printed += write (1, &c, 1);
	}
}

int		ft_zero(int n, int tot)
{
	int				i;
	int				ret;

	i = 0;
	ret = 0;

	while (1 < (tot - n))
	{
		ret += write(1, "0", 1);
		i++;
	}
	return (ret);
}

void	ft_int_flags(t_flags *flags, int *digits)
{
	if (flags->width > 0 && flags->minus != 1)
		ft_width(flags->width, ft_total_digits(flags, digits), flags);
	if (flags->zero > 0 && flags->precision == 1)
		ft_width(flags->zero, ft_total_digits(flags, *digits), flags);
	if ((flags->zero > 0 || flags->precision_l > 0) && flags->negative == 1)
	{
		flags->printed += write(1, "-", 1);
		if (flags->precision_l > 0)
			*digits -= 1;
	}
	if (flags->zero > 0 && flags->minus != 1 && flags->precision == 0)
		flags->printed += ft_zero(*digits, flags->zero);
	if (flags->precision == 1 && flags->precision_l > *digits)
		flags->printed += ft_zero(*digits, flags->precision_l);
}

void	ft_print_int(va_list ap, t_flags *flags)
{
	long long int	num;
	int				digits;
	char			*tmp;

	num = va_arg(ap, int);
	tmp = ft_itoa(num);
	digits = ft_strlen(tmp);
	free(tmp);
	if (num < 0 && num > -2147483648)
	{
		flags->negative = 1;
		num *= -1;
	}
	ft_int_flags(flags, &digits);
	if (num <= -2147483648)
		flags->printed += write (1, "-2147483648", 11);
	else
		ft_putnbr_flags(num, flags);
	if (flags->precision == 1 && flags->precision_l == 0 && flags->width > 0)
		flags->printed += write(1, " ", 1);
	if (flags->zero > 0 && flags->minus == 1)
		flags->width = flags->zero;
	if (flags->width > 0 && flags->minus == 1)
		ft_width(flags->width, ft_total_digits(flags, digits), flags);
}

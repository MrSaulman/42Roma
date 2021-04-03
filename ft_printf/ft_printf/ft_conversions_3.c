/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:56:37 by asalvemi          #+#    #+#             */
/*   Updated: 2021/03/21 18:34:26 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, t_flags *flags)
{
	char			c;

	if(flags->precision != 1 ||
		(flags->precision == 1 && flags->precision_l != 0))
	{
		if (flags->negative == 1 && flags->zero == 0 && flags->precision_l == 0)
		{
			flags->printed += write(1, "-", 1);
			flags->negative = 0;
		}
		if (n > 9)
		{
			ft_putnbr_flags(n / 10, flags);
		}
		c = (n % 10) + '0';
		flags->printed += write (1, &c, 1);
	}
}

void	ft_print_unsigned(va_list ap, t_flags *flags)
{
	unsigned int	num;
	int				digits;
	char			*tmp;

	num = va_arg(ap, unsigned int);
	tmp = ft_itoa(num);
	digits = ft_strlen(tmp);
	free(tmp);
	if (flags->width > 0 && flags->minus != 1)
		ft_width(flags->width, ft_total_digits(flags, digits), flags);
	if (flags->zero > 0 && flags->precision == 1)
		ft_width(flags->zero, ft_total_digits(flags, digits), flags);
	if (flags->zero > 0 && flags->minus != 1 && flags-> precision == 0)
		flags->printed += ft_zero(digits, flags->zero);
	if (flags->precision == 1 && flags ->precision_l == 0 && flags->width > 0)
		flags->printed += write(1, " ", 1);
	if (flags->width > 0 && flags->minus == 1)
		ft_width(flags->width, ft_total_digits(flags, digits), flags);
}

int		ft_hex_len(unsigned int num)
{
	int				i;
	unsigned int	n;

	i = 0;
	n = num;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_dec_to_hex(unsigned int num, t_flags *flags, int is_uppercase)
{
	char			c;
	unsigned int	h;

	c = 0;
	h = 0;
	if (num > 0)
	{
		ft_dec_to_hex(num / 16, flags, is_uppercase);
		h = num % 16;
		if (h > 9)
		{
			if (is_uppercase == 0)
				c = (h - 10) + 'a';
			else
				c = (h - 10) + 'A';
		}
		else if (h <= 9)
			c = h + '0';
		flags->printed += write(1, &c, 1);
	}

}

void	ft_print_hex(va_list ap, t_flags *flags, int is_uppercase)
{
	unsigned int	dec;
	int				l;

	dec = va_arg(ap, unsigned int);
	l = ft_hex_len(dec);
	if (flags->width > 0 && flags->minus != 1)
		ft_width(flags->width, ft_total_digits(flags, l), flags);
	if (flags->zero > 0 && flags->precision == 1)
		ft_width(flags->zero, ft_total_digits(flags, l), flags);
	if (flags->zero > 0 && flags->minus != 1 && flags->precision == 0)
		flags->printed += ft_zero(l, flags->zero);
	if (flags->precision == 1 && flags->precision_l > l)
		flags->printed += ft_zero(l, flags->precision_l > l);
	if (dec == 0 && (flags->precision == 0 ||
	(flags->precision == 1 && flags->precision_l > 0)))
		flags->printed += write(1, "0", 1);
	else if (flags->precision == 0 ||
	(flags->precision == 1 && flags->precision_l > 0))
		ft_dec_to_hex(dec, flags, is_uppercase);
	else if (flags->precision_l > 0 || flags->width > 0)
		flags->printed += write(1, " ", 1);
	if (flags->width > 0 && flags->minus == 1)
		ft_width(flags->width, ft_total_digits(flags, l), flags);
}

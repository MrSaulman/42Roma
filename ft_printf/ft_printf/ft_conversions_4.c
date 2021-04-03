/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:43:14 by asalvemi          #+#    #+#             */
/*   Updated: 2021/03/21 18:08:47 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_p_len(unsigned long int num, t_flags *flags)
{
	int					i;
	unsigned long int	n;

	i = 0;
	n = num;
	if ((n == 0 && flags->precision == 0) ||
	(n == 0 && flags->precision == 1 && flags->precision_l >0))
		i = 1;
	while (n>0)
	{
		n /= 16;
		i++;
	}
	return (i + 2);
}

void	ft_hex_p(unsigned long int n, t_flags *flags)
{
	char				c;
	unsigned long int	h;

	c = 0;
	if (n > 0)
	{
		ft_hex_p(n / 16, flags);
		h = n % 16;
		if (h > 9)
		{
			c = (h - 10) + 'a';
		}
		else if (h <= 9)
			c = h + '0';
		flags->printed += write(1, &c, 1);
	}
}

void	ft_print_pointer(va_list ap, t_flags *flags)
{
	unsigned long int	p;
	unsigned int		len;

	p = va_arg(ap, unsigned long int);
	len = ft_p_len(p, flags);
	if (flags->width > 0 && flags->minus != 1)
		ft_width(flags->width, len, flags),
	flags->printed += write(1, "0x", 2);
	if (flags->zero > 0 && flags->minus != 1)
		flags->printed += ft_zero(len - 2, flags->zero);
	if (flags->precision == 1 && flags->precision_l > (int)(len - 2))
		flags->printed += ft_zero(len - 2, flags->precision_l);
	if ((p == 0 && flags->precision == 0) ||
	(p == 0 && flags->precision == 1 && flags->precision_l > 0))
	{
		flags->printed += 1;
		ft_putnbr_fd(0, 1);
	}
	else if (p > 0)
		ft_hex_p(p, flags);
	if (flags->width > 0 && flags->minus == 1)
		ft_width(flags->width, len, flags);
}

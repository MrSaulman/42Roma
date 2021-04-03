/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:54:43 by asalvemi          #+#    #+#             */
/*   Updated: 2021/03/27 15:14:37 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversions(va_list ap, char c, t_flags *flags)
{
	if (c == 'c')
		ft_chr(ap, flags);
	else if (c == 's')
		ft_string(ap, flags);
	else if (c == 'd' || c == 'i')
		ft_print_int(ap, flags);
	else if (c == 'u')
		ft_print_unsigned(ap, flags);
	else if (c == '%')
		ft_percent(flags);
	else if (c == 'x')
		ft_print_hex(ap, flags, 0);
	else if (c == 'X')
		ft_print_hex(ap, flags, 1);
	else if(c == 'p')
		ft_print_pointer(ap, flags);
}

void	ft_modifiers(const char *s, int *i, t_flags *flags, va_list ap)
{
	char	c;

	c = s[*i];
	if (c == '-' && flags->width == 0)
		flags->minus = 1;
	else if (ft_strchr("123456789*", c))
		ft_get_width(s, i, flags, ap);
	else if (c == '0')
		flags->zero = ft_control_star(s, i, ap, flags);
	else if (c == '.')
	{
		flags->precision = 1;
		flags->precision_l = ft_control_star(s, i, ap, flags);
	}
}

void 	ft_parse_str(t_flags *flags, const char *format, va_list ap, int *i)
{
	if (ft_strchr(CONVERSIONS, format[*i]))
	{
		ft_conversions(ap, format[*i], flags);
		ft_reset_flags(flags);
	}
	else
		ft_modifiers(format, i, flags, ap);
}

int		ft_manage_format(t_flags *flags, const char *format, va_list ap)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			flags->printed += write(1, &format[i], 1);
		else if (format[i] == '%'&& ft_check_segfault(format + i + 1) == 1)
		{
			while (ft_strchr(ALLSIMBOLS, format[i]))
			{
				i++;
				ft_parse_str(flags, format, ap, &i);
				if (ft_strchr(CONVERSIONS, format[i]))
				{
					i++;
					break;
				}
			}
			continue;
		}
		i++;
	}
	return (flags->printed);
}

int		ft_printf(const char *format, ...)
{
	t_flags *flags;
	va_list ap;
	int		printed;

	va_start(ap, format);
	flags = malloc(sizeof(t_flags));
	flags->printed = 0;
	ft_reset_flags(flags);
	ft_manage_format(flags, format, ap);
	printed = flags->printed;
	free(flags);
	return (printed);
}

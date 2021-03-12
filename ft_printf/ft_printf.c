/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:54:43 by asalvemi          #+#    #+#             */
/*   Updated: 2021/02/26 19:55:20 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_parse_str(t_flags *flags, const char *format, va_list ap, int *i)
{
	if (ft_strchr(CONVERSIONS, format[*i]))
	{
		//ft_conversions(ap, format[*i], flags);
		ft_reset_flags(flags);
	}
	//else
	//ft_modifiers(format, i, data, ap);
}

int		ft_manage_format(t_flags *flags, const char *format, va_list ap)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			flags->printed += write(1, &format[i], 1);
		else if (format[i] == '%'&& ft_check_segfault((format + i + 1)) == 1)
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

#include "ft_printf.h"

void	ft_chr(va_list ap, t_flags *flags)
{
	char c;

	c = va_arg(ap, int);
	if(flags->width > 0 && flags->minus != 1)
		ft_width(flags->width, 1, flags);
	flags->printed += write(1, &c, 1);
	if (flags->width > 0 && flags->minus == 1)
		ft_width(flags->width, 1, flags);
}

void	ft_string(va_list ap, t_flags *flags)
{
	const char *str;

	str = (const char *)va_arg(ap, const char *);
	if (str && ft_strlen(str) > 0)
		flags->printed += ft_write_str((char *)str, flags);
	else if (str == NULL)
		flags->printed += ft_write_str("(null)", flags);
	else
		flags->printed += ft_write_str("", flags);
}

void	ft_percent(t_flags *flags)
{
	if (flags->width > 0 && flags->minus != 1)
		ft_width(flags->width, 1, flags);
	if (flags->zero > 0 && flags->minus != 1)
		flags->printed += ft_zero(1, flags->zero);
	flags->printed += write(1, "%", 1);
	if (flags-±width > 0 && flags->minus == 1)
		ft_width(flags->width, 1, flags);
	if (flags->zero > 0 && flags->minus == 1)
		ft_width(flags->zero, 1, flags);
}
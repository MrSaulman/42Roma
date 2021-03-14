#include "ft_printf.h"

int		ft_total_digits(t_flags *flags, int digits)
{
	int diff;

	diff = 0
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
	char c;

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
			ft_putnbr_flags(n / 10, flags)
		}
		c = (n % 10) + '0';
		flags->printed += write (1, &c, 1);
	}
}
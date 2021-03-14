#include "ft_printf.h"

void ft_reset_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->precision_l = 0;
	flags->width = 0;
	flags->negative = 0;
}

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#define ALLSIMBOLS "cspdiuxX%-.*0123456789"
#define CONVERSIONS "cspdiuxX%"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef struct s_printf
{
    int     printed;
    int     minus;
    int     zero;
    int     precision;
    int     precision_l;
    int     width;
    int     negative;
}               t_flags;

int		ft_printf(const char *format, ...);
int     ft_check_segfault(const char *s);
void    ft_reset_flags(t_flags *flags);


#endif //FT_PRINTF_H
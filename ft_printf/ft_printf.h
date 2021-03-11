#ifndef FT_PRINTF_H
#define FT_PRINTF_H

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


#endif //FT_PRINTF_H
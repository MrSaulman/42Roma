#include "ft_printf.h"

int     ft_check_segfault(const char *s)
{
    int     i;
    int     ok;

    i = 0;
    ok = 0;
    while(s[i])
    {
        if (ft_strchr(CONVERSIONS, s[i]))
        {
            ok = 1;
        }
        i++;
    }
    return (ok);
}
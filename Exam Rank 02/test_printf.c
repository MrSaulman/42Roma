#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *s, ...)
{
    va_list list;
    int i;
    int count;

    if (!s)
        return (0);
    i = 0;
    count = 0;

    va_start(list, s);
    
    while (s[i])
    {
        if (s[i] == '%')
        {
            char type = s[i + 1];
            if (type == 's')
            {
                count += ft_putstr(va_arg(list, char *));
            }
            else if (type == 'd')
            {
                count += ft_atoi(va_arg(list, int), "0123456789", 10);
            }
            else if (type == 'x')
            {
                count += ft_atoi(va_arg(list, unsigned int), "0123456789abcdef", 16);
            }
            i += 2;
        }
        if (!s[i])
            return (count);
        count  += ft_putchar(s[i]);
        i++;
    }
    return (count);
}
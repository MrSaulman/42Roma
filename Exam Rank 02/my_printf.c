/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:20:52 by asalvemi          #+#    #+#             */
/*   Updated: 2022/03/15 17:16:38 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
	int count = 0;

	if (!s)
		return (ft_putstr("(null)"));
	while (s[count])
		count += ft_putchar(s[count]);
	return (count);
}

int n_len(long n, int base)
{
	int count = 0;

	if (n == 0)
		count++;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

int ft_atoi(long n, char *ref, int base)
{
	if (n == -2147483648)
	{
		ft_atoi(n / base, ref, base);
		ft_putchar('8');
	}
	else if (n < 0)
	{
		if (base != 16)
		{
			ft_putchar('-');
			ft_atoi(n * -1, ref, base);
		}
		else
			ft_atoi(4294967295 - (n * -1), ref, base);
	}
	else
	{
		if (n < 10)
			ft_putchar('0' + n);
		else
		{
			if (n < 16 && base == 16)
				ft_putchar(ref[n % base]);
			else
			{
				ft_atoi(n / base, ref, base);
				ft_putchar(ref[n % base]);
			}
		}
	}
	return (n_len(n, base));
}

int ft_printf(const char *s, ...)
{
	va_list list;
	int i;
	int count;

	if (!s)
		return (NULL);
	i = 0;
	count = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			char type = s[i + 1];
			if (type == 's')
				count += ft_putstr(va_arg(list, char *));
			else if (type == 'd')
				count += ft_atoi(va_arg(list, int), "0123456789", 10);
			else if (type == 'x')
				count += ft_atoi(va_arg(list, unsigned int), "0123456789abcdef", 16);
			i += 2;
		}
		if (!s[i])
			return (count);
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

#include <stdio.h>
int main()
{
	ft_printf("MIN int: %d\n", -2147483648);
	printf("MIN int: %d\n", -2147483648);
	printf(" - Count ft_printf: %d\n", ft_printf("%d is %x", -13, -13));
	printf(" - Count printf: %d\n", printf("%d is %x", -13, -13));
	printf(" - Count ft_printf: %d\n", ft_printf("%x", -14));
	printf(" - Count printf: %d\n", printf("%x", -14));
	printf(" - Count ft_printf: %d\n", ft_printf("%d", 0));
	printf(" - Count printf: %d\n", printf("%d", 0));
	printf(" - Count ft_printf: %d\n", ft_printf("Hexadecimal for %d is %x", 0, 0));
	printf(" - Count printf: %d\n", printf("Hexadecimal for %d is %x", 0, 0));
	printf(" - Count ft_printf: %d\n", ft_printf("Hexadecimal for %d is %x", 13, 13));
	printf(" - Count printf: %d\n", printf("Hexadecimal for %d is %x", 13, 13));
	printf(" - Count ft_printf: %d\n", ft_printf("%x", 14));
	printf(" - Count printf: %d\n", printf("%x", 14));
	printf(" - Count ft_printf: %d\n", ft_printf("Hexadecimal for %d is %x", 15, 15));
	printf(" - Count printf: %d\n", printf("Hexadecimal for %d is %x", 15, 15));
	printf(" - Count ft_printf: %d\n", ft_printf("Hexadecimal for %d is %x", 16, 16));
	printf(" - Count printf: %d\n", printf("Hexadecimal for %d is %x", 16, 16));
	printf(" - Count ft_printf: %d\n", ft_printf("Hexadecimal for %d is %x", 42, 42));
	printf(" - Count printf: %d\n", printf("Hexadecimal for %d is %x", 42, 42));
	printf(" - Count ft_printf: %d\n", ft_printf("%d", 3456));
	printf(" - Count printf: %d\n", printf("%d", 3456));
	printf(" - Count ft_printf: %d\n", ft_printf("%x", 3456));
	printf(" - Count printf: %d\n", printf("%x", 3456));
	printf(" - Count ft_printf: %d\n", ft_printf("%s", NULL));
	printf(" - Count printf: %d\n", printf("%s", NULL));
	printf(" - Count ft_printf: %d\n", ft_printf("Hello %s", "toto"));
	printf(" - Count printf: %d\n", printf("Hello %s", "toto"));
	printf(" - Count ft_printf: %d\n", ft_printf("Magic %s is %d", "number", 42));
	printf(" - Count printf: %d\n", printf("Magic %s is %d", "number", 42));
}

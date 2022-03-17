

#include <stdio.h> 
int main()
{
  	// ft_printf("MIN int: %d\n", -2147483648);
	// printf("MIN int: %d\n", -2147483648);
  	printf(" - Count ft_printf: %d\n", ft_printf("%d", 0));
	printf(" - Count printf: %d\n", printf("%d", 0));
	printf(" - Count ft_printf: %d\n", ft_printf("%x", 0));
	printf(" - Count printf: %d\n", printf("%x", 0));
	printf(" - Count ft_printf: %d\n", ft_printf("Hexadecimal for %d is %x", 13, 13));
	printf(" - Count printf: %d\n", printf("Hexadecimal for %d is %x", 13, 13));
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
	printf(" - Count ft_printf: %d\n", ft_printf("Hexadecimal for %d is %x", 42, 42));
	printf(" - Count printf: %d\n", printf("Hexadecimal for %d is %x", 42, 42));
}
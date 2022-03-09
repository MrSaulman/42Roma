

#include <stdio.h> 
int main()
{
    ft_printf("Ma guarda un %s\n", "po'");
	printf("Ma guarda un %s\n", "po'");
    ft_printf("MIN int: %d\n", -2147483648);
	printf("MIN int: %d\n", -2147483648);
	// ft_printf("%s\n", NULL);
	// printf("%s\n", NULL);
    printf(" - Count ft_printf: %d\n", ft_printf("%s", NULL));
	printf(" - Count printf: %d\n", printf("%s", NULL));
	// printf(" - Count ft_printf: %d\n", ft_printf("Hello %s", "toto"));
	// printf(" - Count printf: %d\n", printf("Hello %s", "toto"));
	// printf(" - Count ft_printf: %d\n", ft_printf("%s %s", "I'm"));
	// printf(" - Count printf: %d\n", printf("%s %s", "I'm"));
	printf(" - Count ft_printf: %d\n", ft_printf("Magic %s is %d", "number", 42));
	printf(" - Count printf: %d\n", printf("Magic %s is %d", "number", 42));
	printf(" - Count ft_printf: %d\n", ft_printf("Hexadecimal for %d is %x", 42, 42));
	printf(" - Count printf: %d\n", printf("Hexadecimal for %d is %x", 42, 42));
}

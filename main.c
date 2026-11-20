#include "ft_printf.h"

int main(void)
{
	char p = 'c';

	printf("%c\n", "hello");
	ft_printf("%c\n", "hello");
	printf("\n");

	ft_printf("\n");
	
	char *s = NULL;

	int a = printf(" NULL %s NULL \n", s);
	int b = ft_printf(" NULL %s NULL \n", s);
	printf("%d %d\n", a, b);
	ft_printf("\n");

	printf("%p\n", &p);
	ft_printf("%p\n", &p);

	ft_printf("\n");

	printf("%d\n", 255);
	ft_printf("%d\n", 255);

	ft_printf("\n");

	printf("%i\n", 255);
	ft_printf("%i\n", 255);

	ft_printf("\n");

	printf("%u\n", 255);
	ft_printf("%u\n", 255);

	ft_printf("\n");

	printf("%x\n", 255);
	ft_printf("%x\n", 255);

	ft_printf("\n");

	printf("%X\n", 255);
	ft_printf("%X\n", 255);

	ft_printf("\n");

	printf("%%\n", 255);
	ft_printf("%%\n", 255);

	ft_printf("\n");
}

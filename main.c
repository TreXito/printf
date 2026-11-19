#include "ft_printf.h"

int main(void)
{
	int r1, r2;

r1 = ft_printf("a%db\n", 42);          r2 = printf("a%db\n", 42);          printf("%d %d\n", r1, r2);
r1 = ft_printf("%s|%c|%x\n", "hi", 'z', 255);
r2 = printf("%s|%c|%x\n", "hi", 'z', 255);                                printf("%d %d\n", r1, r2);
r1 = ft_printf("%d%d\n", 1, 2);        r2 = printf("%d%d\n", 1, 2);        printf("%d %d\n", r1, r2);
r1 = ft_printf("100%%\n");             r2 = printf("100%%\n");             printf("%d %d\n", r1, r2);
}

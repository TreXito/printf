#include "ft_printf.h"

static void *ft_printc(void *input)
{
	char *c;

	c = (char *)input;
	write(1, *c, 1);
}

static void *ft_prints(void *input)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)input;
	while (*s)
		i++;
	write(1, &s, i);
}

static void *ft_printp(void *input)
{
	char	*hexTable;
	char	c;
	int		n;

	hexTable = "0123456789abcdef";
	n = (unsigned int)input;
	if (n > 15)
		ft_printx(n / 16);
	write(1, hexTable[n % 16], 1);
}

static void *ft_printd(void *input)
{
	char	c;
	int		n;

	n = (int)input;
	if (n < 0)
	{
		write (1, "-", 1);
		if (n == -2147483648)
		{
			write(1, "2147483648", 11);
			return ;
		}
		n = -n;
	}
	if (n > 9)
		ft_printd(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

static void *ft_printi(void *input)
{
	ft_printd(input);
}

• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.

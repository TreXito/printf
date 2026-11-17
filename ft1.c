#include "ft_printf.h"

int ft_printc(int c)
{
	const char *ch;

	ch = c;
	write(1, &ch, 1);
}

int ft_prints(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (*str)
		i++;
	write(1, &str, i);
}

int ft_printp(void *p)
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

int ft_printd(int n)
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

int ft_printi(int n)
{
	ft_printd(input);
}

/*• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
*/
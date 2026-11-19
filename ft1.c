#include "ft_printf.h"

int ft_printc(int c, int count)
{
	char ch;

	ch = (char)c;
	write(1, &ch, 1);
	return (count++);
}

int ft_prints(char *s, int count)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (*str)
		i++;
	write(1, &str, i);
	count =+ i;
	return (count);
}

int ft_printp(void *p, int count)
{
	char				*hexTable;
	unsigned long		n;

	hexTable = "0123456789abcdef";
	n = (unsigned long)p;
	if (n > 15)
	{
		count++;
		ft_printx(n / 16, count);
	}
	write(1, &hexTable[n % 16], 1);
	return (count);
}

int ft_printd(int n, int count)
{
	char	c;

	if (n < 0)
	{
		count += 1;
		write (1, "-", 1);
		if (n == -2147483648)
		{
			write(1, "2147483648", 11);
			count += 10;
			return (count);
		}
		n = -n;
	}
	if (n > 9)
	{
		count++;
		ft_printd(n / 10, count);
	}
	c = n % 10 + '0';
	write(1, &c, 1);
	return (count);
}

/*• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
*/
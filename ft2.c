#include "ft_printf.h"

int ft_printu(unsigned int n, int count)
{
	char				c;

	if (n > 9)
	{
		ft_printd(n / 10, count);
	}
	c = n % 10 + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int ft_printxlow(unsigned long n, int count)
{
	char	*hexTable;

	hexTable = "0123456789abcdef";
	if (n > 15)
	{
		count++;
		ft_printxlow(n / 16, count);
	}
	write(1, &hexTable[n % 16], 1);
	count++;
	return (count);
}

int ft_printxup(unsigned long n, int count)
{
	char				*hexTable;

	hexTable = "0123456789ABCDEF";
	if (n > 15)
	{
		count++;
		ft_printxup(n / 16, count);
	}
	write(1, &hexTable[n % 16], 1);
	count++;
	return (count);
}

int ft_printPERC(int count)
{
	write(1, "%", 1);
	return (count + 1);
}

/*• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign. */
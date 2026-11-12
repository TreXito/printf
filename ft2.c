#include "ft_printf.h"

static void *ft_printu(void *input)
{
	char				c;
	unsigned int		n;

	n = (unsigned int)input;
	if (n > 9)
		ft_printd(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

static void *ft_printx(void *input)
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

static void *ft_printX(void *input)
{
	char				*hexTable;
	char				c;
	unsigned int		n;

	hexTable = "0123456789abcdef";
	n = (unsigned int)input;
	if (n > 15)
		ft_printx(n / 16);
	write(1, hexTable[n % 16], 1);
}

static void *ft_printPERC(void *input)
{
	write(1, '%', 1);
}

• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
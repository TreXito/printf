#include "ft_printf.h"

int ft_printu(unsigned int n)
{
	char				c;
	unsigned int		n;

	n = (unsigned int)input;
	if (n > 9)
		ft_printd(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int ft_printx(unsigned int n)
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

int ft_printX(unsigned int n)
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

int ft_printPERC(void)
{
	write(1, '%', 1);
}

/*• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign. */
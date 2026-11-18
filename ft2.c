#include "ft_printf.h"

int ft_printu(unsigned int n, int count)
{
	char				c;

	if (n > 9)
		ft_printd(n / 10, count);
	c = n % 10 + '0';
	write(1, &c, 1);
	if (n < 10)
		return (count);
}

int ft_printx(unsigned int n, int count)
{
	char	*hexTable;

	//write 00x (i think) before?
	hexTable = "0123456789abcdef";
	if (n > 15)
		ft_printx(n / 16, count);
	write(1, hexTable[n % 16], 1);
	if (n < 16 )
		return (count);
}

int ft_printX(unsigned int n, int count)
{
	char				*hexTable;

	hexTable = "0123456789abcdef";
	if (n > 15)
		ft_printx(n / 16, count);
	write(1, hexTable[n % 16], 1);
	if (n < 16 )
		return (count);
}

int ft_printPERC(void)
{
	write(1, '%', 1);
	return (1);
}

/*• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign. */
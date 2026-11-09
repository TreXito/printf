#include "ft_printf.h"

void *ft_printu(void *input)
{

}

void *ft_printx(void *input)
{

}

void *ft_printX(void *input)
{

}

void *ft_printPERC(void *input)
{
	write(1, '%', 1);
}

• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
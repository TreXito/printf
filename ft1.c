/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:15:58 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/21 16:18:22 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printc(int c, int count)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	write (1, &ch, 1);
	return (++count);
}

int	ft_prints(char *s, int count)
{
	int		i;

	i = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (count + 6);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	count += i;
	return (count);
}

int	ft_printp(void *p, int count)
{
	char				*hextable;
	unsigned long		n;

	hextable = "0123456789abcdef";
	n = (unsigned long)p;
	if (p == NULL)
	{
		write (1, "(nil)", 5);
		return (count + 5);
	}
	else
	{
		write (1, "0x", 2);
		count += 2;
	}
	if (n > 15)
		count = ft_printxlow(n / 16, count);
	write (1, &hextable[n % 16], 1);
	count++;
	return (count);
}

int	ft_printd(int n, int count)
{
	char	c;

	if (n < 0)
	{
		count++;
		write (1, "-", 1);
		if (n == -2147483648)
		{
			write (1, "2147483648", 10);
			count += 10;
			return (count);
		}
		n = -n;
	}
	if (n > 9)
		count = ft_printd(n / 10, count);
	c = n % 10 + '0';
	write (1, &c, 1);
	count++;
	return (count);
}

/*• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:36:46 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/21 16:25:17 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	modstring(char input_mod, va_list *args, int counter);

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1] != '\0')
		{
			counter = modstring(input[i + 1], &args, counter);
			i += 2;
		}
		else
		{
			write (1, &input[i], 1);
			i++;
			counter++;
		}
	}
	va_end(args);
	return (counter);
}

static int	modstring(char input_mod, va_list *args, int counter)
{
	if (input_mod == 'c')
		counter = ft_printc(va_arg(*args, int), counter);
	else if (input_mod == 's')
		counter = ft_prints(va_arg(*args, char *), counter);
	else if (input_mod == 'p')
		counter = ft_printp(va_arg(*args, void *), counter);
	else if (input_mod == 'd' || input_mod == 'i')
		counter = ft_printd(va_arg(*args, int), counter);
	else if (input_mod == 'u')
		counter = ft_printu(va_arg(*args, unsigned int), counter);
	else if (input_mod == 'x')
		counter = ft_printxlow(va_arg(*args, unsigned int), counter);
	else if (input_mod == 'X')
		counter = ft_printxup(va_arg(*args, unsigned int), counter);
	else if (input_mod == '%')
		counter = ft_printperc(counter);
	else
	{
		write (1, "%", 1);
		write (1, &input_mod, 1);
		counter += 2;
	}
	return (counter);
}

/* int main(void)
{
	char p = 'c';

	printf("%c\n", "hello");
	ft_printf("%c\n", "hello");
	printf("\n");

	ft_printf("\n");
	
	char *s = NULL;

	int a = printf(" NULL %s NULL \n", s);
	int b = ft_printf(" NULL %s NULL \n", s);
	printf("%d %d\n", a, b);
	ft_printf("\n");

	printf(" %p %p ", 0, 0);
	ft_printf(" %p %p ", 0, 0);

	ft_printf("\n");

	printf("%d\n", 255);
	ft_printf("%d\n", 255);

	ft_printf("\n");

	printf("%i\n", 255);
	ft_printf("%i\n", 255);

	ft_printf("\n");

	printf("%u\n", 255);
	ft_printf("%u\n", 255);

	ft_printf("\n");

	printf("%x\n", 255);
	ft_printf("%x\n", 255);

	ft_printf("\n");

	printf("%X\n", 255);
	ft_printf("%X\n", 255);

	ft_printf("\n");

	printf("%%\n", 255);
	ft_printf("%%\n", 255);

	ft_printf("\n");
}*/
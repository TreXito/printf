/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:36:46 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/19 20:40:05 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int modString(char input_mod, va_list *args, int counter);

int	ft_printf(const char *input, ...)
{
	va_list args;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(args, input);
	while (input[i])
	{ 
		if (input[i] == '%' && input[i + 1] != '\0')
		{
			counter += modString(input[i + 1], &args, i);
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

int modString(char input_mod, va_list *args, int counter)
{
	if (input_mod == 'c')
		counter = ft_printc(va_arg(*args, int), counter);
	else if (input_mod == 's')
		counter = ft_prints(va_arg(*args, char *), counter);
	else if (input_mod == 'p')
		counter = ft_printp(va_arg(*args, void *), counter);
	else if  (input_mod == 'd' || input_mod == 'i')
		counter = ft_printd(va_arg(*args, int), counter);
	else if  (input_mod == 'u')
		counter = ft_printu(va_arg(*args, unsigned int), counter);
	else if  (input_mod == 'x')
		counter = ft_printx(va_arg(*args, unsigned int), counter);
	else if  (input_mod == 'X')
		counter = ft_printX(va_arg(*args, unsigned int), counter);
	else if  (input_mod == '%')
		counter = ft_printPERC(counter);
	else
	{
		write(1, "%", 1);
		write(1, &input_mod, 1);
		counter += 2;
	}
	return (counter);
}// return length of new string

/*char *conversion(char *input)
{
	char *conversions;
	int i;
	char *input_mod;

	input_mod = malloc(2);
	conversions = "cspdiuxX%";
	i = 0;
	while (*input)
	{ 
		while (conversions[i]){ 
			if (*input == "%" && *input == conversions[i])
			{
				input_mod[0] = "%";
				 input_mod =  conversions[i];
			}
				else if (input == "%")
				i++;
			else
				input++;
		}
	}
	return (input_mod);
}*/

/*int main(void)
{
	printf("hello world%d blabla", 341);
}*/
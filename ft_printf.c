/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:36:46 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/12 22:14:53 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list args;
	int i;
	char *input_mod;
	char *conversions;
	input_mod = malloc(2);
	conversions = "cspdiuxX%";
	va_start(args, input);
	
	i = 0;
	while (*input)
	{ 
		while (conversions[i]){ 
			if (*input == "%" && *(input + 1) == conversions[i])
				return(modString(*(input + 1), input, args));
				
			else
			{
				write (1, *input, 1);
				input++;
			}
		
	}
	va_end(args);
//ft_printf("i am %s and trexito", fat) would print i am fat and trexito
}

char *modString(char input_mod, const char *input, va_list args)
{
	if (input_mod[1] == 'c')
		ft_printc(input);
	else if (input_mod[1] == 's')
		ft_prints(input);
	else if (input_mod[1] == 'p')
		ft_printp(input);
	else if  (input_mod[1] == 'd')
		ft_printd(input);
	else if  (input_mod[1] == 'i')
		ft_printi(input);
	else if  (input_mod[1] == 'u')
		ft_printu(input);
	else if  (input_mod[1] == 'x')
		ft_printx(input);
	else if  (input_mod[1] == 'X')
		ft_printX(input);
	else if  (input_mod[1] == '%')
		ft_printPERC(input);
}

char *conversion(char *input)
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
				 input_mod[1] =  conversions[i];
			}
				else if (input == "%")
				i++;
			else
				input++;
		}
	}
	return (input_mod);
}

int main(void)
{
	printf("hello world%d blabla", 341);
}
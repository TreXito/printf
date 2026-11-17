/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:36:46 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/17 18:52:32 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int modString(char input_mod, const char *input, va_list args);

int	ft_printf(const char *input, ...)
{
	va_list args;
	int		i;
	int		j;
	char	*conversions;

	i = 0;
	j = 0;
	conversions = "cspdiuxX%";
	va_start(args, input);
	while (input[j])
	{ 
		while (conversions[i])
		{ 
			if (input[j] == '%' && input[j + 1] == conversions[i])
				j += modString(input[j + 1], input, args);
			else
				i++;
		}	
	write (1, &input[j], 1);
	j++;
	}		
	va_end(args);
}

int modString(char input_mod, const char *input, va_list args)
{
	char *inchar;

	inchar = (char *)input;
	if (input_mod == 'c')
		ft_printc(inchar);
	else if (input_mod == 's')
		ft_prints(inchar);
	else if (input_mod == 'p')
		ft_printp(inchar);
	else if  (input_mod == 'd')
		ft_printd(inchar);
	else if  (input_mod == 'i')
		ft_printi(inchar);
	else if  (input_mod == 'u')
		ft_printu(inchar);
	else if  (input_mod == 'x')
		ft_printx(inchar);
	else if  (input_mod == 'X')
		ft_printX(inchar);
	else if  (input_mod == '%')
		ft_printPERC(inchar);
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

int main(void)
{
	printf("hello world%d blabla", 341);
}
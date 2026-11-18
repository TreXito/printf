/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:36:46 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/18 17:29:04 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int modString(char input_mod, const char *input, va_list *args);

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
				j += modString(input[j + 1], input, &args, j);
			else
				i++;
		}	
	write (1, &input[j], 1);
	j++;
	}		
	va_end(args);
	return (j);
}

int modString(char input_mod, const char *input, va_list *args, int counter)
{
	if (input_mod == 'c')
		counter += ft_printc(va_arg(*args, int));
	else if (input_mod == 's')
		counter += ft_prints(va_arg(*args, char *));
	else if (input_mod == 'p')
		return(ft_printp(va_arg(*args, void *)));
	else if  (input_mod == 'd')
		return(ft_printd(va_arg(*args, int)));
	else if  (input_mod == 'i')
		return(ft_printi(va_arg(*args, int)));
	else if  (input_mod == 'u')
		return(ft_printu(va_arg(*args, unsigned int)));
	else if  (input_mod == 'x')
		return(ft_printx(va_arg(*args, unsigned int)));
	else if  (input_mod == 'X')
		return(ft_printX(va_arg(*args, unsigned int)));
	else if  (input_mod == '%')
		return(ft_printPERC(va_arg(*args, void));
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:36:46 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/06 15:38:06 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list args;
	int i;
	char *input_mod;
	
	i = 0;
	input_mod = conversion(input);
	va_start(args, input);
	
	
	va_end(args);
}

char *modString(char *conversions)
{
	char *print;

	if (conversions[0])
	
}

char *print(char *mod)
{
	
}

char *conversion(char *input)
{
	char *conversions;
	int i;
	char *input_mod;

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
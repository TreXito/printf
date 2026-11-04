/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:36:46 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/04 15:26:49 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	char *conversions;
	va_list args;
	int i;
	char *input_mod;
	
	i = 0;
	conversions = "cspdiuxX%";
	va_start(args, input);

	while (*input)
	{ 
		while (conversions[i]){ 
			if (*input == "%" && *input + 1 == conversions[i])
				input_mod = "%", conversions[i];
			else if (input == "%")
				i++;
			else
				input++;
		}
	}
	va_end(args);
}

int main(void)
{
	printf("hello world%d blabla", 341);
}
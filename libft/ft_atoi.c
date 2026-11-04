/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:49:14 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/02 14:04:35 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	converted;
	int	sign;

	sign = 1;
	converted = 0;
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		converted = converted * 10 + *nptr - '0';
		nptr++;
	}
	return (sign * converted);
}

/*int main(void)
{
	char *numba = "+-42";
//	char escape[] = {9, 10, 11, 12, 13, 0};

	printf("%d", ft_atoi(numba));
}
*/
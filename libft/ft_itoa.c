/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:02:24 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/02 08:18:53 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:02:24 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/01 14:30:00 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calcsize(long n)
{
	int	size;

	size = 1;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*c;
	long	nb;
	int		len;
	int		negative;

	nb = (long)n;
	negative = (nb < 0);
	if (negative)
		nb = -nb;
	len = ft_calcsize(nb) + negative;
	c = malloc(len + 1);
	if (c == NULL)
		return (NULL);
	c[len] = '\0';
	while (len > 0)
	{
		c[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (negative)
		c[0] = '-';
	return (c);
}

/*int	main(void)
{
	//int	i;
	//int	intmax;

	//intmax = 2147483647;
	//i = 0;
	printf("%s", ft_itoa(0));
}*/

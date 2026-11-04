/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 18:54:09 by ppodobri          #+#    #+#             */
/*   Updated: 2026/10/29 11:41:38 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	itc;

	itc = (unsigned char)c;
	i = 0;
	while (!(s[i] == '\0'))
	{
		if (s[i] == itc)
			return ((char *)s + i);
		i++;
	}
	if (itc == '\0')
		return ((char *)s + i);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 19:01:12 by ppodobri          #+#    #+#             */
/*   Updated: 2026/10/29 12:29:42 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*last;
	unsigned char	itc;

	itc = (unsigned char)c;
	i = 0;
	last = NULL;
	while (!(s[i] == '\0'))
	{
		if (s[i] == itc)
			last = (char *)s + i;
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (last);
}

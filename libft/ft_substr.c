/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:28:19 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/02 09:02:57 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		i = 0;
	else
	{
		while ((s[start + i] != '\0') && len > i)
			i++;
	}
	subs = malloc (i + 1);
	if (subs == NULL)
		return (NULL);
	if (i >= 1)
		subs[i] = '\0';
	else
		subs[0] = '\0';
	while (i > 0)
	{
		subs[i - 1] = s[start + i - 1];
		i--;
	}
	return (subs);
}
/*int main (void)
{
	printf ("%s", ft_substr("tripouille", 1, 1));
}*/
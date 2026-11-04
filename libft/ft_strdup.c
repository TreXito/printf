/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:10:50 by ppodobri          #+#    #+#             */
/*   Updated: 2026/10/30 14:34:46 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*mods;
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	mods = malloc (sizeof(char) * i + 1);
	if (mods == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		mods[i] = s[i];
		i++;
	}
	mods[i] = '\0';
	return (mods);
}

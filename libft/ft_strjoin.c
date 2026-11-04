/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 10:28:59 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/02 14:06:00 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	char		*concs;

	i = 0;
	j = 0;
	concs = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (concs == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		concs[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		concs[i + j] = s2[j];
		j++;
	}
	concs[i + j] = '\0';
	return (concs);
}

/*int main(void)
{
	char	*str;
	int		i;

	str = ft_strjoin("hello","world");
	i = 0;
	printf("%s ", str);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:43:28 by ppodobri          #+#    #+#             */
/*   Updated: 2026/10/26 12:06:29 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*srccopy;

	srccopy = (char *)src;
	i = 0;
	while (!(*srccopy == '\0'))
	{
		i++;
		srccopy++;
	}
	if (size == 0)
		return (i);
	while (size - 1 > 0 && (!(*src == '\0')))
	{
		*dst = *src;
		size--;
		dst++;
		src++;
	}
	if (size > 0)
		*dst = '\0';
	return (i);
}

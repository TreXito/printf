/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:30:52 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/02 13:58:10 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (ft_strlen(dst) > size)
		dstlen = size;
	else
		dstlen = ft_strlen(dst);
	if (size == 0)
		return (srclen);
	if (size > dstlen + 1)
	{
		while (size - (dstlen + i) > 1 && src[i] != '\0')
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		if (dstlen + i < size)
			dst[dstlen + i] = '\0';
	}
	return (srclen + dstlen);
}

/*int main(void)
{
	char dest[30]; 
	ft_memset(dest, 0, 30);
	printf("%zu", ft_strlcat(dest, "123", 3));
	printf("\n");
	printf("%s", dest);
}*/
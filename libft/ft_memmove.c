/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 15:40:46 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/02 13:58:00 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (d > s)
	{
		while (n > 0)
		{
			d[n -1] = s[n -1];
			n--;
		}
	}
	else if (s > d || d == s)
		d = ft_memcpy(dest, src, n);
	return (dest);
}

/*int main(void)
{
	unsigned char s[] = "hello";
	unsigned char d[] = "buf";
	printf(ft_memmove(d,s,4));
	
}*/

/*
unsigned char	*d;
	unsigned char	*s;
	unsigned char	*tempa;
	unsigned char	*tempa2;
	size_t			ncopy;

	*tempa2 = *tempa;
	ncopy = n;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n > 0)
	{
		*tempa = *s;
		n--;
		s++;
		tempa++;
	}
	while (ncopy > 0)
	{
		*d = *tempa2;
		d++;
		tempa2++;
		ncopy--;
	}
	return (dest);
	*/
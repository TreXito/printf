/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:53:39 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/02 14:05:29 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*returnval;

	if (size != 0 && n > ((size_t)-1) / size)
		return (NULL);
	returnval = malloc(n * size);
	if (returnval == NULL)
	{
		return (NULL);
		free (returnval);
	}
	ft_memset(returnval, 0, n * size);
	return (returnval);
}

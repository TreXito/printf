/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:53:54 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/02 14:07:56 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:53:54 by ppodobri          #+#    #+#             */
/*   Updated: 2026/10/29 15:40:09 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char addOne(unsigned int i, char c);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rs;
	int		i;

	i = 0;
	rs = malloc(ft_strlen(s) + 1);
	if (rs == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		rs[i] = f((unsigned int) i, s[i]);
		i++;
	}
	rs[i] = '\0';
	return (rs);
}

/*char addOne(unsigned int i, char c)
 {
	return (i + c);
}*/
/*int main(void)
{
	const char *s;

	s = "1234";
	printf("%s", ft_strmapi(s, addOne));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:20:54 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/02 16:26:10 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_malloc_outer(const char *s, char c);
static int		ft_malloc_inner(const char *s, char c, int i);
static char		*ft_write_string(const char *s, char c, int i);
static void		*free_all(char **output, int wi);

char	**ft_split(const char *s, char c)
{
	int		wi;
	char	**output;
	int		i;

	i = 0;
	wi = 0;
	output = malloc(ft_malloc_outer(s, c) + sizeof(char *));
	if (output == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			output[wi] = ft_write_string(s, c, i);
			if (output[wi] == NULL)
				return (free_all(output, wi - 1));
			wi++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	output[wi] = NULL;
	return (output);
}

static int	ft_malloc_outer(const char *s, char c)
{
	int	strct;

	strct = 0;
	while (*s == c && *s != '\0')
		s++;
	while (*s != '\0')
	{
		if ((*s != c && *(s + 1) == c) || (*s != c && *(s + 1) == '\0'))
			strct++;
		s++;
	}
	return (strct * sizeof(char *));
}

static int	ft_malloc_inner(const char *s, char c, int i)
{
	int	cc;

	cc = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		cc++;
	}
	return (cc * sizeof(char));
}

static char	*ft_write_string(const char *s, char c, int i)
{
	char	*string;
	int		j;

	j = 0;
	string = malloc(ft_malloc_inner(s, c, i) + sizeof(char));
	if (string == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		string[j] = s[i];
		i++;
		j++;
	}
	string[j] = '\0';
	return (string);
}

static void	*free_all(char **output, int wi)
{
	while (wi >= 0)
	{
		free (output[wi]);
		wi--;
	}
	free (output);
	return (NULL);
}

/*int main(void)
{
	char test[] = ",,,hi,,,,hello,hjaja,,,,";

	char ** poopstinky;
	poopstinky = ft_split(test, ',');
	while (*poopstinky != NULL)
	{
		printf("%s\n" ,*poopstinky);
		poopstinky++;
	}
	
}
	*/

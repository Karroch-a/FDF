/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:33:30 by aazeroua          #+#    #+#             */
/*   Updated: 2019/11/20 21:29:31 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_cwordcount(const char *s, char c)
{
	int i;

	i = (s[0] != c ? 1 : 0);
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			i++;
		s++;
	}
	return (i);
}

static int	ft_clettercount(const char *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			return (i);
		i++;
		s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		index;
	char	**new;

	if (!s ||
	!(new = (char **)malloc(sizeof(char*) * (ft_cwordcount(s, c) + 1))))
		return (NULL);
	i = 0;
	index = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
		{
			new[index] = (char *)malloc(sizeof(*s) *
					(ft_clettercount(&s[i], c) + 1));
			ft_strncpy(new[index], &s[i], ft_clettercount(&s[i], c));
			new[index][ft_clettercount(&s[i], c)] = '\0';
			index++;
		}
		i++;
	}
	new[index] = 0;
	return (new);
}

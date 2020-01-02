/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:54:52 by aazeroua          #+#    #+#             */
/*   Updated: 2019/04/09 23:49:43 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*a;

	if (s)
	{
		if (!(a = ft_strnew(len)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			a[i] = s[start];
			i++;
			start++;
		}
		a[i] = '\0';
		return (a);
	}
	return (NULL);
}

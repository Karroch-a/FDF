/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:27:55 by aazeroua          #+#    #+#             */
/*   Updated: 2019/04/15 21:54:17 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*a;
	size_t	n;

	if (*s2 == '\0')
		return ((char *)s1);
	a = (char *)s1;
	n = ft_strlen(s2);
	while (*a)
	{
		if (!ft_memcmp(a++, s2, n))
			return (a - 1);
	}
	return (0);
}

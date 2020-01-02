/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:18:38 by aazeroua          #+#    #+#             */
/*   Updated: 2019/04/04 22:51:21 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	int		n;

	n = ft_strlen(s);
	a = (char *)s + n;
	while (n >= 0)
	{
		if (*a == c)
			return (a);
		a--;
		n--;
	}
	return (NULL);
}

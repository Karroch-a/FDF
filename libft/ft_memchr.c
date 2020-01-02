/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 22:49:49 by aazeroua          #+#    #+#             */
/*   Updated: 2019/04/03 23:42:59 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned int	i;
	unsigned char	b;

	i = 0;
	a = (unsigned char *)s;
	b = (unsigned char)c;
	while (i < n)
	{
		if (*a != b)
			a++;
		else
			return (a);
		i++;
	}
	return (NULL);
}

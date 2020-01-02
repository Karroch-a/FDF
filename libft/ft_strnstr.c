/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:08:58 by aazeroua          #+#    #+#             */
/*   Updated: 2019/04/15 23:28:47 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t s2_len;

	if (*s2 == '\0')
		return ((char *)s1);
	s2_len = ft_strlen(s2);
	while (*s1 && len >= s2_len)
	{
		if (!ft_memcmp(s1, s2, len > s2_len ? s2_len : len))
			return ((char *)s1);
		s1++;
		len--;
	}
	return (0);
}

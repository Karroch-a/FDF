/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:09:01 by aazeroua          #+#    #+#             */
/*   Updated: 2019/04/06 14:47:35 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned char	*sr;
	unsigned int	dlen;
	unsigned int	srlen;
	unsigned int	i;

	sr = (unsigned char *)src;
	i = 0;
	dlen = ft_strlen(dst);
	srlen = ft_strlen(src);
	if (size > dlen)
	{
		while (*dst)
			dst++;
		while ((dlen + i < size - 1) && (*sr != '\0'))
		{
			*dst = *sr;
			i++;
			dst++;
			sr++;
		}
		*dst = '\0';
	}
	return (size < dlen ? size + srlen : dlen + srlen);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:52:07 by aazeroua          #+#    #+#             */
/*   Updated: 2019/04/07 23:04:55 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *s;

	if ((s = (char *)malloc(size)) == NULL)
		return (NULL);
	ft_memset(s, '\0', size);
	return ((void *)s);
}

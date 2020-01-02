/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:08:25 by aazeroua          #+#    #+#             */
/*   Updated: 2019/04/03 01:26:51 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int c, size_t e)
{
	unsigned char *po;

	po = (unsigned char *)a;
	while (e--)
	{
		*po++ = (unsigned char)c;
	}
	return (a);
}

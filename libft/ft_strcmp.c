/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:50:56 by aazeroua          #+#    #+#             */
/*   Updated: 2019/04/21 02:04:30 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	res;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	res = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (a[i] || b[i])
	{
		if (a[i] == b[i])
			i++;
		else
		{
			res = a[i] - b[i];
			break ;
		}
	}
	return (res);
}

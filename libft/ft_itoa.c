/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:48:14 by aazeroua          #+#    #+#             */
/*   Updated: 2019/11/21 00:25:32 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_number(int c)
{
	int i;

	i = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		i++;
	while (c != 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	long int	mod;
	long int	dev;
	char		*a;
	int			i;

	dev = n;
	i = count_number(n);
	a = malloc(i + 1);
	if (!a)
		return (NULL);
	a[i] = '\0';
	while (dev != 0)
	{
		mod = dev % 10;
		if (n < 0)
			mod = mod * -1;
		a[--i] = mod + 48;
		dev = dev / 10;
	}
	if (n < 0)
		a[--i] = '-';
	if (n == 0)
		a[--i] = '0';
	return (a);
}

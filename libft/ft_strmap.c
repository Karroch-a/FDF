/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:46:48 by aazeroua          #+#    #+#             */
/*   Updated: 2019/04/18 19:30:35 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*as;

	i = 0;
	as = NULL;
	if (!s)
		return (NULL);
	if (s)
	{
		as = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (as == NULL)
			return (NULL);
		else
		{
			while (s[i])
			{
				as[i] = f(s[i]);
				i++;
			}
		}
	}
	as[i] = '\0';
	return (as);
}

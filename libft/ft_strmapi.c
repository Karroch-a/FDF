/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:41:15 by aazeroua          #+#    #+#             */
/*   Updated: 2019/04/18 19:31:21 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				as[i] = f(i, s[i]);
				i++;
			}
		}
	}
	as[i] = '\0';
	return (as);
}

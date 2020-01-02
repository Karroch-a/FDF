/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:17:09 by aazeroua          #+#    #+#             */
/*   Updated: 2019/04/11 17:14:18 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	char	*fin;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s) - 1;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == 32)
		i++;
	while (i <= len && (s[len] == '\t' || s[len] == '\n' || s[len] == 32))
		len--;
	if (!(fin = ft_strnew(len + 1 - i)))
		return (NULL);
	ft_strncpy(fin, (s + i), (len - i + 1));
	fin[len - i + 1] = '\0';
	return (fin);
}

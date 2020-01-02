/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:36:19 by aazeroua          #+#    #+#             */
/*   Updated: 2019/05/20 02:10:20 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_line(char **tab, int fd, int *i, char **line)
{
	while (tab[fd][*i] != '\n' && tab[fd][*i] != '\0')
		*i = *i + 1;
	*line = ft_strsub(tab[fd], 0, *i);
}

int				get_next_line(const int fd, char **line)
{
	int			i;
	int			rd;
	char		buff[BUFF_SIZE + 1];
	static char	*tab[4864];
	char		*tm;

	if (fd < 0 || !line || fd > 4864 || read(fd, buff, 0) < 0)
		return (-1);
	if (!tab[fd])
		tab[fd] = ft_strnew(0);
	i = 0;
	while ((!ft_strchr(tab[fd], '\n')) && (rd = read(fd, buff, BUFF_SIZE)))
	{
		buff[rd] = '\0';
		tm = ft_strjoin(tab[fd], buff);
		free(tab[fd]);
		tab[fd] = tm;
	}
	if (rd < 1 && !tab[fd][i])
		return (rd);
	ft_line(tab, fd, &i, line);
	tm = ft_strdup(tab[fd][i] == '\n' ? &tab[fd][i + 1] : ft_strdup("\0"));
	free(tab[fd]);
	tab[fd] = tm;
	return (1);
}

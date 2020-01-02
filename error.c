/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:49:45 by aazeroua          #+#    #+#             */
/*   Updated: 2019/11/24 06:12:34 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_usage(void)
{
	ft_putendl("Usage : ./fdf <filename>");
	exit(0);
}

int		check_error(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (get_next_line(fd, &line) <= 0)
	{
		if (get_next_line(fd, &line) == 0)
		{
			ft_putendl("no data file");
			exit(0);
		}
		perror("");
		exit(0);
	}
	return (1);
}

void	ft_free(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != NULL)
		ft_memdel((void **)tmp[i++]);
	free(tmp);
}

void	ft_free_int(int **tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != NULL)
		ft_memdel((void **)tmp[i++]);
	free(tmp);
}

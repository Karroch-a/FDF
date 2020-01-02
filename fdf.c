/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:35:24 by aazeroua          #+#    #+#             */
/*   Updated: 2019/11/24 06:54:53 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_var		*ft_calc(char *file, t_var *dim)
{
	int		fd;
	char	*line;

	dim->len = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		dim->len++;
		ft_memdel((void **)(&line));
	}
	close(fd);
	return (dim);
}

void		ft_len(char *file, t_var *dim)
{
	int		fd;
	char	*line;
	int		*tab;
	int		j;

	ft_calc(file, dim);
	fd = open(file, O_RDONLY);
	tab = (int *)ft_memalloc(sizeof(int) * dim->len);
	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tab[j++] = ft_cwordcount(line, ' ');
		ft_memdel((void **)(&line));
	}
	j = 0;
	while (j < dim->len)
	{
		if (tab[0] > tab[j++] || tab[0] == 0)
		{
			ft_putendl("file note valid");
			exit(0);
		}
	}
	dim->min = tab[0];
	ft_memdel((void **)&tab);
}

char		**ft_stock(char *file, t_var *dim)
{
	int		fd;
	char	**stock;
	int		len;
	int		i;
	char	*line;

	i = 0;
	len = dim->len;
	stock = (char **)ft_memalloc(sizeof(char *) * dim->len + 1);
	stock[dim->len] = NULL;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		stock[i] = line;
		i++;
	}
	return (stock);
}

int			**ft_stock_int(char **stock, t_var *dim)
{
	char	**tmp;
	int		**stock2;
	int		i;
	int		j;

	i = 0;
	stock2 = (int **)ft_memalloc(sizeof(int *) * dim->len);
	while (i < dim->len)
	{
		tmp = ft_strsplit(stock[i], ' ');
		stock2[i] = (int *)ft_memalloc(sizeof(int) * dim->min);
		j = 0;
		while (j < dim->min)
		{
			stock2[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		i++;
	}
	return (stock2);
}

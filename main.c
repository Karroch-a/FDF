/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:35:35 by aazeroua          #+#    #+#             */
/*   Updated: 2019/11/24 20:28:20 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu(t_var *dim)
{
	mlx_string_put(dim->ptr, dim->win, 40, 40, 0xFFFFFF, "MOVE WITH ARROW KEY");
	mlx_string_put(dim->ptr, dim->win, 40, 90, 0xFFFFFF, "ISO WITH key I");
	mlx_string_put(dim->ptr, dim->win, 40, 140, 0xFFFFFF, "PRA WITH key P");
	mlx_string_put(dim->ptr, dim->win, 40, 190, 0xFFFFFF,
							"INCREASE ALTITUDE key U");
	mlx_string_put(dim->ptr, dim->win, 40, 240, 0xFFFFFF,
							"DICREASE ALTITUDE key D");
}

void	ft_hight_width(int keycode, t_var **dim2)
{
	if (keycode == 123)
		(*dim2)->w = (*dim2)->w - 10;
	if (keycode == 124)
		(*dim2)->w = (*dim2)->w + 10;
	if (keycode == 125)
		(*dim2)->h = (*dim2)->h + 10;
	if (keycode == 126)
		(*dim2)->h = (*dim2)->h - 10;
}

int		key_press(int keycode, t_var *dim2)
{
	mlx_clear_window(dim2->ptr, dim2->win);
	ft_menu(dim2);
	if (keycode == 53)
		exit(0);
	ft_hight_width(keycode, &dim2);
	if (keycode == 78 && dim2->dis - 0.5 > 0)
		dim2->dis--;
	if (keycode == 69)
		dim2->dis++;
	if (keycode == 32)
		dim2->scale += 1.2;
	if (keycode == 2)
		dim2->scale -= 1.2;
	if (keycode == 34 || (dim2->mod == 1 && keycode != 35))
	{
		dim2->mod = 1;
		ft_drow(dim2);
	}
	if (keycode == 35 || dim2->mod == 0)
	{
		dim2->mod = 0;
		ft_drow(dim2);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	**tmp;
	t_var	dim;

	dim.w = 0;
	dim.h = 0;
	dim.dis = 0;
	dim.scale = 0.1;
	if (argc == 2 && check_error(argv[1]))
	{
		dim.ptr = mlx_init();
		dim.win = mlx_new_window(dim.ptr, W, H, "FDF");
		ft_menu(&dim);
		ft_len(argv[1], &dim);
		tmp = ft_stock(argv[1], &dim);
		dim.stock = ft_stock_int(tmp, &dim);
		ft_drow(&dim);
		mlx_hook(dim.win, 2, 0, key_press, &dim);
		mlx_loop(&dim.ptr);
		ft_free_int(dim.stock);
		ft_free(tmp);
	}
	ft_usage();
	return (0);
}

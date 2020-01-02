/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:26:21 by aazeroua          #+#    #+#             */
/*   Updated: 2019/11/24 21:17:52 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(float *x, float *y, int z, int scale)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z * (scale) + (previous_x + previous_y) * sin(0.523599);
}

void		ft_line_calcul(t_var *dim, t_point point, float x1, float y1)
{
	(dim)->dx = x1 - point.x;
	(dim)->dy = y1 - point.y;
	(dim)->dx = (dim)->dx < 0 ? -(dim)->dx : (dim)->dx;
	(dim)->dy = (dim)->dy < 0 ? -(dim)->dy : (dim)->dy;
	(dim)->max = (dim)->dy > (dim)->dx ? (dim)->dy : (dim)->dx;
	(dim)->dx = x1 - point.x;
	(dim)->dy = y1 - point.y;
	(dim)->dx = (dim)->dx / (dim)->max;
	(dim)->dy = (dim)->dy / (dim)->max;
}

void		ft_b(t_point point, float x1, float y1, t_var *dim)
{
	if (dim->mod == 1)
	{
		dim->z0 = dim->stock[(int)point.y][(int)point.x];
		dim->z1 = dim->stock[(int)y1][(int)x1];
		iso(&(point.x), &(point.y), dim->z0, dim->scale);
		iso(&x1, &y1, dim->z1, dim->scale);
	}
	ft_centre(dim);
	point.x = (point.x * dim->centre + (W / 2)
				- (dim->min * dim->centre / 2)) + dim->w;
	point.y = (point.y * dim->centre + (H / 2)
				- (dim->len * dim->centre / 2)) + dim->h;
	x1 = (x1 * dim->centre + (W / 2) - (dim->min * dim->centre / 2)) + dim->w;
	y1 = (y1 * dim->centre + (H / 2) - (dim->len * dim->centre / 2)) + dim->h;
	ft_line_calcul(dim, point, x1, y1);
	while ((int)(x1 - point.x) != 0 || (int)(y1 - point.y) != 0)
	{
		mlx_pixel_put(dim->ptr, dim->win, point.x, point.y, dim->color);
		point.x += dim->dx;
		point.y += dim->dy;
	}
}

void		ft_drow(t_var *dim)
{
	t_point point;

	point.y = 0;
	while (point.y < dim->len)
	{
		point.x = 0;
		while (point.x < dim->min)
		{
			if (dim->stock[(int)(point.y)][(int)point.x] == 0)
				dim->color = 0xff;
			else
				dim->color = 0x000FFF * abs(dim->stock[(int)point.y]
							[(int)point.x]);
			if (dim->min - 1 > point.x)
			{
				ft_b(point, point.x + 1, point.y, dim);
			}
			if (dim->len - 1 > point.y)
				ft_b(point, point.x, point.y + 1, dim);
			point.x++;
		}
		point.y++;
	}
}

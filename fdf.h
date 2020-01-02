/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 22:35:49 by aazeroua          #+#    #+#             */
/*   Updated: 2019/11/24 05:57:05 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define H 1500
# define W 1500

# include "libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include "mlx.h"
# include <stdio.h>
# include <math.h>

typedef struct	s_point
{
	float			x;
	float			y;
}				t_point;

typedef struct	s_var
{
	int			min;
	int			len;
	int			color;
	int			centre;
	int			iso;
	void		*ptr;
	void		*win;
	int			**stock;
	int			max;
	float		dx;
	float		dy;
	float		w;
	float		h;
	int			mod;
	float		dis;
	int			z0;
	int			z1;
	double		scale;
}				t_var;

void			ft_len(char *file, t_var *dim);
char			**ft_stock(char *file, t_var *dim);
int				**ft_stock_int(char **stock, t_var *dim);
void			ft_b(t_point point, float x1, float y1, t_var *dim);
void			ft_drow(t_var *dim);
void			ft_centre(t_var *dim);
int				key_press(int keycode, t_var *dim2);
t_var			*ft_calc(char *file, t_var *dim);
void			ft_drow_iso(t_var *dim);
void			ft_b_iso(float x0, float y0, float x1, float y1, t_var *dim);
int				check_error(char *file);
void			ft_usage(void);
void			ft_free(char **tmp);
void			ft_free_int(int **tmp);

#endif

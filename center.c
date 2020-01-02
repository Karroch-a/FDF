/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:37:52 by aazeroua          #+#    #+#             */
/*   Updated: 2019/11/20 21:43:09 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_centre(t_var *dim)
{
	int slen;
	int smin;

	dim->centre = 1;
	slen = 1;
	smin = 1;
	while (smin * dim->min <= W * 0.5)
		smin++;
	while (slen * dim->len <= H * 0.5)
		slen++;
	if (smin < slen)
		dim->centre = smin + dim->dis;
	else
		dim->centre = slen + dim->dis;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:25:54 by nbethany          #+#    #+#             */
/*   Updated: 2019/07/17 12:43:49 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
** Finds current posisiton between 2 color and returns
** a position in percentage
*/

double			get_percentage_color(double start, double end, double current)
{
	double		placement;
	double		distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

/*
** Using linear interpolation (get_pixel_color) this function
** finds a value for ecah color channel and then returns decimal value of color
*/

int				get_line_color(int color1, int color2, double color_grad)
{
	int			red;
	int			green;
	int			blue;

	if (color1 == color2)
		return (color1);
	red = (int)get_pixel_color(((color1 >> 16) & 0xFF),
			((color2 >> 16) & 0xFF), color_grad);
	green = (int)get_pixel_color(((color1 >> 8) & 0xFF),
			((color2 >> 8) & 0xFF), color_grad);
	blue = (int)get_pixel_color((color1 & 0xFF), (color2 & 0xFF), color_grad);
	return ((red << 16) | (green << 8) | blue);
}

int				get_pixel_color(double start, double end, double current)
{
	return ((int)start * (1.0 - current) + (end * current));
}

int				calculate_color(t_fdf *fdf, t_map *map, t_point point)
{
	int			color;
	int			diff;
	double		diff_pcnt;

	if (abs(point.z - map->min_z) <= abs(point.z - map->mid_z))
	{
		diff = map->mid_z - map->min_z;
		if (diff != 0)
			diff_pcnt = (point.z - map->min_z) / (double)diff;
		else
			diff_pcnt = 0.0;
		color = get_line_color(fdf->color_min, fdf->color_mid, diff_pcnt);
		return (color);
	}
	else
	{
		diff = map->max_z - map->mid_z;
		if (diff != 0)
			diff_pcnt = (point.z - map->mid_z) / (double)diff;
		else
			diff_pcnt = 0.0;
		color = get_line_color(fdf->color_mid, fdf->color_max, diff_pcnt);
		return (color);
	}
}

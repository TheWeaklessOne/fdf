/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:18:06 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/17 12:18:43 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		iso(int *x, int *y, int z)
{
	int			previous_x;
	int			previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

static void		scale_point(t_point *point, t_fdf *fdf)
{
	point->x *= fdf->scale;
	point->y *= fdf->scale;
	point->z *= fdf->scale;
}

static void		translate_point(t_point *point, int x_sft, int y_sft, int z_sft)
{
	point->x += x_sft;
	point->y += y_sft;
	point->z += z_sft;
}

t_point			transform_point(t_fdf *fdf, t_map *map, int row, int column)
{
	t_point		current_point;
	t_point		new_point;
	double		map_middle_z;
	double		map_middle_x;
	double		map_middle_h;

	map_middle_x = (map->width - 1) / 2;
	map_middle_h = (map->height - 1) / 2;
	map_middle_z = (map->max_z + map->min_z) / 2;
	new_point = map->points[index_matr(row, column, map->width)];
	current_point = new_point;
	translate_point(&new_point, -map_middle_x, -map_middle_h, -map_middle_z);
	scale_point(&new_point, fdf);
	rotate_x_around(&new_point.y, &new_point.z, fdf->x_rotation);
	rotate_y_around(&new_point.x, &new_point.z, fdf->y_rotation);
	rotate_z_around(&new_point.x, &new_point.y, fdf->z_rotation);
	if (fdf->camera == ISO)
		iso(&new_point.x, &new_point.y, new_point.z);
	translate_point(&new_point, (WIDTH + MENU_WIDTH) / 2, HEIGHT / 2, 0);
	translate_point(&new_point, fdf->x_shift, fdf->y_shift, fdf->z_shift);
	if (current_point.color < 0)
		new_point.color = calculate_color(fdf, map, current_point);
	return (new_point);
}

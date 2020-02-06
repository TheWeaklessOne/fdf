/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 22:17:20 by nbethany          #+#    #+#             */
/*   Updated: 2019/07/17 13:21:19 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_line		set_line(t_point point_0, t_point point_1)
{
	t_line			line;

	line.x0 = (int)point_0.x;
	line.y0 = (int)point_0.y;
	line.x1 = (int)point_1.x;
	line.y1 = (int)point_1.y;
	line.dx = ABS(line.x1 - line.x0);
	line.dy = ABS(line.y1 - line.y0);
	line.sx = line.x0 < line.x1 ? 1 : -1;
	line.sy = line.y0 < line.y1 ? 1 : -1;
	line.error = line.dx - line.dy;
	line.color_grad = 0.0;
	return (line);
}

int					is_drawn(t_fdf *fdf, t_line line, t_point p0, t_point p1)
{
	int				coord_z;

	if (line.y0 >= 0 && line.y0 < HEIGHT && line.x0 >= 0 && line.x0 < WIDTH)
	{
		coord_z = get_pixel_color(p0.z, p1.z, line.color_grad);
		if (coord_z > fdf->coord[index_matr(line.y0, line.x0, WIDTH)])
		{
			fdf->coord[index_matr(line.y0, line.x0, WIDTH)] = coord_z;
			return (0);
		}
	}
	return (1);
}

void				draw_line(t_fdf *elem, t_point p0, t_point point1)
{
	t_line			line;

	line = set_line(p0, point1);
	while (1)
	{
		(line.dx > line.dy) ?
			(line.color_grad = get_percentage_color(p0.x, point1.x, line.x0)) :
			(line.color_grad = get_percentage_color(p0.y, point1.y, line.y0));
		line.color = get_line_color(p0.color, point1.color, line.color_grad);
		if (!is_drawn(elem, line, p0, point1))
			img_pixel_put(&elem->image, line.x0, line.y0, line.color);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		line.error2 = line.error * 2;
		if (line.error2 > -line.dy)
		{
			line.error -= line.dy;
			line.x0 += line.sx;
		}
		if (line.error2 < line.dx)
		{
			line.error += line.dx;
			line.y0 += line.sy;
		}
	}
}

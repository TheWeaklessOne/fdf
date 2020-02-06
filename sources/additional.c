/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:17:20 by nbethany          #+#    #+#             */
/*   Updated: 2019/07/17 14:09:54 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			free_fdf(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->image.image);
}

void			put_pixels(t_fdf *fdf)
{
	t_point		point;
	int			row;
	int			column;
	int			map_w;

	row = fdf->map.height;
	map_w = fdf->map.width;
	while (--row > -1)
	{
		column = map_w;
		while (--column > -1)
		{
			point = transform_point(fdf, &fdf->map, row, column);
			fdf->map.xpoints[index_matr(row, column, map_w)] = point;
			img_pixel_put(&fdf->image, point.x, point.y, point.color);
		}
	}
}

void			clear_background(t_image *img)
{
	int			i;
	int			*image;

	image = (int *)(img->ptr);
	i = HEIGHT * WIDTH;
	while (--i > -1)
	{
		if (i % WIDTH < MENU_WIDTH)
			i -= MENU_WIDTH - 1;
		image[i] = BACKGROUND_COLOR;
	}
}

int				render_image(t_fdf *fdf)
{
	t_point		point;
	int			row;
	int			column;
	int			map_w;

	clear_background(&fdf->image);
	init_coord(fdf);
	put_pixels(fdf);
	row = fdf->map.height;
	map_w = fdf->map.width;
	while (--row > -1)
	{
		column = map_w;
		while (--column > -1)
		{
			point = fdf->map.xpoints[index_matr(row, column, map_w)];
			(row + 1 < fdf->map.height) ? draw_line(fdf, point,
					fdf->map.xpoints[index_matr(row + 1, column, map_w)]) : 0;
			(column + 1 < map_w) ? draw_line(fdf, point,
					fdf->map.xpoints[index_matr(row, column + 1, map_w)]) : 0;
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image.image, 0, 0);
	menu(fdf);
	return (1);
}

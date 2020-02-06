/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:21:18 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/17 14:05:09 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			menu(t_fdf *elem)
{
	int			p;

	p = 0;
	mlx_string_put(elem->mlx, elem->window, 15, p += 20, TC,
			"Zoom: Mouse wheel");
	mlx_string_put(elem->mlx, elem->window, 15, p += 20, TC,
			"Move: Arrow keys");
	mlx_string_put(elem->mlx, elem->window, 65, p += 30, TC, "Rotate:");
	mlx_string_put(elem->mlx, elem->window, 15, p += 20, TC, "X-Axis");
	mlx_string_put(elem->mlx, elem->window, 15, p += 20, TC, "[Q] [E] MOUSE1");
	mlx_string_put(elem->mlx, elem->window, 15, p += 20, TC, "Y-Axis");
	mlx_string_put(elem->mlx, elem->window, 15, p += 20, TC, "[A] [D] MOUSE1");
	mlx_string_put(elem->mlx, elem->window, 15, p += 20, TC, "Z-Axis");
	mlx_string_put(elem->mlx, elem->window, 15, p += 20, TC, "[Z] [C]");
	mlx_string_put(elem->mlx, elem->window, 15, p += 30, TC,
			"Change projection:");
	mlx_string_put(elem->mlx, elem->window, 15, p += 20, TC, "Parallel");
	mlx_string_put(elem->mlx, elem->window, 15, p += 20, TC, "[P]");
	mlx_string_put(elem->mlx, elem->window, 15, p += 20, TC, "Isometric");
	mlx_string_put(elem->mlx, elem->window, 15, p += 20, TC, "[I]");
	mlx_string_put(elem->mlx, elem->window, 15, p += 30, TC, "Change colors:");
	mlx_string_put(elem->mlx, elem->window, 15, p += 20, TC, "NUMPAD [1 - 4]");
	mlx_string_put(elem->mlx, elem->window, 15, p += 30, TC, "Exit: ESC");
}

void			init_mouse(t_fdf *fdf)
{
	t_mouse		*mouse;

	mouse = &fdf->mouse;
	mouse->pressed = 0;
	mouse->x0 = 0;
	mouse->y0 = 0;
	mouse->x = 0;
	mouse->y = 0;
}

/*
** Initializes buffer with MIN_INT for right
** hidden lines drawing in drawer.c
*/

void			init_coord(t_fdf *fdf)
{
	int			i;

	i = (int)WIDTH * HEIGHT;
	while (--i > -1)
	{
		if (i % WIDTH < MENU_WIDTH)
			i -= MENU_WIDTH - 1;
		fdf->coord[i] = -2147483648;
	}
}

void			init_menu(t_fdf *elem)
{
	int			*image;
	int			i;

	i = WIDTH * HEIGHT;
	image = (int *)(elem->image.ptr);
	while (--i > -1)
	{
		if (i % WIDTH < MENU_WIDTH)
			image[i] = MENU_BACKGROUND_COLOR;
		else
			i -= WIDTH - MENU_WIDTH - 1;
	}
}

void			init_elem(t_fdf *elem)
{
	double		x_scale;
	double		y_scale;

	elem->mlx = mlx_init();
	elem->window = mlx_new_window(elem->mlx, WIDTH, HEIGHT, "FDF");
	initialize_image(elem);
	init_mouse(elem);
	init_coord(elem);
	x_scale = (WIDTH - MENU_WIDTH) / elem->map.width / 2;
	y_scale = HEIGHT / elem->map.height / 2;
	elem->scale = x_scale > y_scale ? y_scale : x_scale;
	elem->camera = PAR;
	reset_fdf(elem);
	elem->color_max = 0xF5A142;
	elem->color_mid = 0xF54275;
	elem->color_min = 0x9042F5;
	init_menu(elem);
}

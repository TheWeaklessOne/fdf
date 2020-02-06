/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:17:20 by nbethany          #+#    #+#             */
/*   Updated: 2019/07/17 13:49:14 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			mouse_trans_pressed(int button, int x, int y, t_fdf *fdf)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (button == 1)
		{
			(&fdf->mouse)->x = x;
			(&fdf->mouse)->y = y;
			(&fdf->mouse)->pressed = 1;
		}
		else if (button == 4 && fdf->scale - 2 >= 0)
			fdf->scale -= 2;
		else if (button == 5)
			fdf->scale += 2;
		render_image(fdf);
	}
	return (0);
}

int			mouse_trans_moved(int x, int y, t_fdf *fdf)
{
	t_mouse	*mouse;

	mouse = &fdf->mouse;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		mouse->x0 = mouse->x;
		mouse->y0 = mouse->y;
		mouse->x = x;
		mouse->y = y;
		if (mouse->pressed)
		{
			fdf->x_rotation -= (mouse->y0 - y) / 180;
			fdf->y_rotation += (mouse->x0 - x) / 180;
		}
		if (mouse->pressed)
			render_image(fdf);
	}
	return (0);
}

int			mouse_trans_released(int button, int x, int y, t_fdf *fdf)
{
	t_mouse	*mouse;

	mouse = &fdf->mouse;
	(void)button;
	(void)x;
	(void)y;
	mouse->pressed = 0;
	return (0);
}

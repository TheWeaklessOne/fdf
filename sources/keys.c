/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:45:42 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/17 18:17:20 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			key_down_one(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
	{
		free_fdf(fdf);
		exit(EXIT_SUCCESS);
	}
	else if (key == KEY_P)
	{
		fdf->camera = PAR;
		reset_fdf(fdf);
	}
	else if (key == KEY_I)
	{
		fdf->camera = ISO;
		reset_fdf(fdf);
	}
	else
		return (key_down_two(key, fdf));
	return (render_image(fdf));
}

int			key_down_two(int key, t_fdf *fdf)
{
	if (key == KEY_NUMPAD_1)
	{
		fdf->color_max = 0xF5A142;
		fdf->color_mid = 0xF54275;
		fdf->color_min = 0x9042F5;
	}
	else if (key == KEY_NUMPAD_2)
	{
		fdf->color_max = 0xFFFFFF;
		fdf->color_mid = 0xFFFFFF;
		fdf->color_min = 0xFFFFFF;
	}
	else if (key == KEY_NUMPAD_3)
	{
		fdf->color_max = 0x51befc;
		fdf->color_mid = 0x4154e8;
		fdf->color_min = 0xcc9c00;
	}
	else if (key == KEY_NUMPAD_4)
	{
		fdf->color_max = 0x8ED943;
		fdf->color_mid = 0x27E8B1;
		fdf->color_min = 0x2757E8;
	}
	return (render_image(fdf));
}

int			key_trans(int key, t_fdf *fdf)
{
	if (key == KEY_UP)
		fdf->y_shift -= 5;
	else if (key == KEY_DOWN)
		fdf->y_shift += 5;
	else if (key == KEY_RIGHT)
		fdf->x_shift += 5;
	else if (key == KEY_LEFT)
		fdf->x_shift -= 5;
	else if (key == KEY_Q)
		fdf->x_rotation += 0.05;
	else if (key == KEY_E)
		fdf->x_rotation -= 0.05;
	else if (key == KEY_A)
		fdf->y_rotation += 0.05;
	else if (key == KEY_D)
		fdf->y_rotation -= 0.05;
	else if (key == KEY_Z)
		fdf->z_rotation += 0.05;
	else if (key == KEY_C)
		fdf->z_rotation -= 0.05;
	render_image(fdf);
	return (0);
}

void		free_split(char ***to_free)
{
	char	**split;
	int		i;

	split = *to_free;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

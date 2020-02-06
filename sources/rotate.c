/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:19:34 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/17 14:03:27 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			index_matr(int row, int column, int map_width)
{
	return (row * map_width + column);
}

void		rotate_x_around(int *y, int *z, double alpha)
{
	int			previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void		rotate_y_around(int *x, int *z, double beta)
{
	int			previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void		rotate_z_around(int *x, int *y, double gamma)
{
	int			previous_x;
	int			previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void		reset_fdf(t_fdf *elem)
{
	elem->x_rotation = 0;
	elem->y_rotation = 0;
	elem->z_rotation = 0;
	elem->x_shift = 0;
	elem->y_shift = 0;
	elem->z_shift = 0;
}

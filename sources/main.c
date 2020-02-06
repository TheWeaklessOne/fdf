/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:30:22 by nbethany          #+#    #+#             */
/*   Updated: 2019/07/17 11:28:55 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static	int	close_app(void *param)
{
	(void)param;
	exit(0);
}

void		ft_error(char *msg, int i)
{
	ft_putstr(msg);
	exit(i);
}

int			main(int argc, char *argv[])
{
	t_fdf	elem;
	int		fd;

	if (argc != 2)
		ft_error("usage: ./fdf *input_file*\n", 0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("File cannot be opened\n", 0);
	if (!reader(&elem.map, fd))
		ft_error("Something is wrong with file inputs\n", 0);
	close(fd);
	init_elem(&elem);
	render_image(&elem);
	mlx_key_hook(elem.window, key_down_one, &elem);
	mlx_hook(elem.window, 2, (1L << 0), key_trans, &elem);
	mlx_hook(elem.window, 4, (1L << 2), mouse_trans_pressed, &elem);
	mlx_hook(elem.window, 5, (1L << 3), mouse_trans_released, &elem);
	mlx_hook(elem.window, 6, (1L << 13), mouse_trans_moved, &elem);
	mlx_hook(elem.window, 17, 0L, close_app, &elem);
	mlx_loop((&elem)->mlx);
	free(elem.map.points);
	free(elem.map.xpoints);
	exit(0);
}

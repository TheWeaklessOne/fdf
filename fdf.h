/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:30:53 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/17 18:16:48 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <math.h>
# include "./minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>

# define WIDTH 1600
# define HEIGHT 900
# define MENU_WIDTH 200
# define TC 0xFFFFFF
# define BACKGROUND_COLOR 0x000000
# define MENU_BACKGROUND_COLOR 0x202020

# define KEY_ESC 53

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define KEY_NUMPAD_1 83
# define KEY_NUMPAD_2 84
# define KEY_NUMPAD_3 85
# define KEY_NUMPAD_4 86

# define KEY_Q 12
# define KEY_E 14
# define KEY_A 0
# define KEY_D 2
# define KEY_Z 6
# define KEY_C 8
# define KEY_P 35
# define KEY_I 34

# define ISO 0
# define PAR 1

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_line
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			error;
	int			error2;
	double		color_grad;
	int			color;
}				t_line;

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			line_s;
	int			endian;
}				t_image;

typedef struct	s_map
{
	int			width;
	int			height;
	int			max_z;
	int			min_z;
	int			mid_z;
	int			min_diff_mid_z;
	t_point		*points;
	t_point		*xpoints;
}				t_map;

typedef struct	s_mouse
{
	double		x;
	double		y;
	double		x0;
	double		y0;
	int			pressed;
}				t_mouse;

typedef struct	s_fdf
{
	t_map		map;
	void		*mlx;
	void		*window;
	t_image		image;
	t_mouse		mouse;
	int			coord[WIDTH * HEIGHT];
	double		x_rotation;
	double		y_rotation;
	double		z_rotation;
	int			x_shift;
	int			y_shift;
	int			z_shift;
	int			scale;
	char		camera;
	int			color_min;
	int			color_mid;
	int			color_max;
}				t_fdf;

void			ft_error(char *msg, int i);

int				reader(t_map *array_list, int fd);

double			get_percentage_color(double start, double end, double current);
int				get_pixel_color(double start, double end, double current);
int				get_line_color(int color1, int color2, double color_grad);
int				calculate_color(t_fdf *fdf, t_map *map, t_point point);
void			fill_struct(t_map *map, t_list *data);

void			img_pixel_put(t_image *img, double x, double y, int color);
void			initialize_image(t_fdf *fdf);

void			init_elem(t_fdf *elem);
void			init_coord(t_fdf *fdf);
void			init_mouse(t_fdf *fdf);

void			rotate_x_around(int *y, int *z, double alpha);
void			rotate_y_around(int *x, int *z, double beta);
void			rotate_z_around(int *x, int *y, double gamma);

int				mouse_trans_pressed(int button, int x, int y, t_fdf *fdf);
int				mouse_trans_moved(int x, int y, t_fdf *fdf);
int				mouse_trans_released(int button, int x, int y, t_fdf *fdf);

t_point			transform_point(t_fdf *fdf, t_map *map, int row, int column);

void			lstdel(t_list **lst);

void			reset_fdf(t_fdf *elem);
void			free_fdf(t_fdf *fdf);
void			free_split(char ***to_free);

void			menu(t_fdf *elem);

int				key_trans(int key, t_fdf *fdf);
int				key_down_two(int key, t_fdf *fdf);
int				key_down_one(int key, t_fdf *fdf);

void			clear_background(t_image *img);
void			draw_line(t_fdf *elem, t_point p0, t_point point_1);
int				render_image(t_fdf *fdf);
int				index_matr(int row, int column, int map_width);

#endif

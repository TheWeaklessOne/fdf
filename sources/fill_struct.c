/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:02:46 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/17 14:03:02 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int			hex_atoi(char *str)
{
	int				len;
	size_t			res;
	int				rank;

	if (!(str[0] == ',' && str[1] == '0' && (str[2] == 'x' || str[2] == 'X')))
		return (-1);
	str += 3;
	len = ft_strlen(str);
	if (len > 6)
		return (-1);
	res = 0;
	rank = 0;
	while (--len > -1)
	{
		if (str[len] >= '0' && str[len] <= '9')
			res += (str[len] - '0') * pow(16, rank++);
		else if (str[len] >= 'A' && str[len] <= 'F')
			res += (str[len] - 55) * pow(16, rank++);
		else
			return (-1);
	}
	return (res);
}

static int			validate_number(char *number, t_point *point)
{
	size_t			len;
	size_t			i;

	i = (*number == '-' || *number == '+');
	len = ft_strlen(number);
	while (i < len)
	{
		if (!ft_isdigit(number[i]))
		{
			if (number[i] == ',')
			{
				if ((i = hex_atoi(number + i)) != -1)
				{
					point->color = i;
					return (1);
				}
			}
			ft_error("Something is wrong with file inputs\n", 0);
		}
		i++;
	}
	point->color = -1;
	return (1);
}

static t_point		get_point(t_map *map, char *split, int row, int column)
{
	t_point			point;
	char			*number;

	number = split;
	point.x = (double)column;
	point.y = (double)row;
	if (!validate_number(number, &point))
		ft_error("Something is wrong with file inputs\n", 0);
	point.z = (double)ft_atoi(split);
	if (point.z > map->max_z)
		map->max_z = point.z;
	if (point.z < map->min_z)
		map->min_z = point.z;
	return (point);
}

static void			find_mid_z(t_map *map)
{
	int				i;
	t_point			point;

	i = map->height * map->width;
	while (--i >= 0)
	{
		point = map->points[i];
		if (abs((int)((map->max_z + map->min_z) / 2) - point.z) <
				map->min_diff_mid_z)
		{
			map->min_diff_mid_z = abs((int)((map->max_z + map->min_z)
						/ 2) - point.z);
			map->mid_z = point.z;
		}
	}
	if (map->mid_z == map->min_z)
		map->mid_z = map->max_z;
}

void				fill_struct(t_map *map, t_list *data)
{
	t_list			*current_elem;
	int				column;
	int				row;
	char			**split;

	current_elem = data;
	row = map->height;
	map->max_z = -2147483648;
	map->min_z = 2147483647;
	map->min_diff_mid_z = 2147483647;
	while (--row >= 0)
	{
		column = map->width - 1;
		split = ft_strsplit((char *)current_elem->content, ' ');
		while (column >= 0)
		{
			map->points[index_matr(row, column, map->width)] =
					get_point(map, split[column], row, column);
			column--;
		}
		current_elem = current_elem->next;
		free_split(&split);
	}
	find_mid_z(map);
}

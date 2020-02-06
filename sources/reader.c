/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:17:20 by nbethany          #+#    #+#             */
/*   Updated: 2019/07/17 13:59:33 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
** Checks line if it has any digits if none is found returns 0 otherwise 1
*/

int				check_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
** Reads a line, checks it for validation and if all is ok
** adds a line into the list and returns 1 otherwise 0
*/

static int		get_line(t_map *map, t_list **data, int fd)
{
	t_list		*line_data;
	char		*line;

	line_data = NULL;
	while ((get_next_line(fd, &line) > 0))
	{
		if (!check_line(line))
			return (0);
		if (map->width == 0)
			map->width = (int)ft_count_words(line, ' ');
		else if (map->width != (int)ft_count_words(line, ' '))
			return (0);
		line_data = ft_lstnew(line, ft_strlen(line) + 1);
		ft_lstadd(data, line_data);
		map->height++;
		free(line);
	}
	return (1);
}

void			lstdel(t_list **lst)
{
	t_list		*curr;
	t_list		*tmp;

	curr = *lst;
	while (curr)
	{
		free(curr->content);
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}

int				reader(t_map *fdf_map, int fd)
{
	t_list		*map;

	map = NULL;
	fdf_map->height = 0;
	fdf_map->width = 0;
	if (!get_line(fdf_map, &map, fd) || !map)
		return (0);
	fdf_map->points = malloc(fdf_map->height *
								fdf_map->width * sizeof(t_point));
	if (!fdf_map->points)
		return (0);
	fdf_map->xpoints = malloc(fdf_map->height *
			fdf_map->width * sizeof(t_point));
	if (!fdf_map->xpoints)
	{
		free(fdf_map->points);
		return (0);
	}
	fill_struct(fdf_map, map);
	lstdel(&map);
	return (1);
}

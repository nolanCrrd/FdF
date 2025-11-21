/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:33:04 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/21 09:55:04 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/ft_printf.h"
#include "../../includes/get_next_line_bonus.h"
#include <stdlib.h>

void	clean_exit(int fd, char *line, t_point **lst, char *msg)
{
	char	*line_clear;

	ft_dprintf(2, "%s\n", msg);
	clear_point_lst(lst);
	free(line);
	line_clear = get_next_line(fd);
	while (line_clear != NULL)
	{
		free(line_clear);
		line_clear = get_next_line(fd);
	}
	exit(1);
}

static int	add_point_static_lst(t_point **list, t_point *point, int x, int y)
{
	static int	i = 0;

	point->x = x;
	point->y = y;
	list[i++] = point;
	return (0);
}

static void	fill_altitude_map(t_map *map, t_point *point)
{
	if (point->altitude > map->map_max_altitude)
		map->map_max_altitude = point->altitude;
	if (point->altitude < map->map_min_altitude)
		map->map_min_altitude = point->altitude;
}

void	create_point_line(t_map *map, int fd, char *line, int y)
{
	int		i;
	int		current_x;
	t_point	*current_point;

	i = 0;
	current_x = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			current_point = get_first_point(&line[i]);
			if (current_point == NULL)
				clean_exit(fd, line, map->lst, "Malloc error");
			add_point_static_lst(map->lst, current_point, current_x, y);
			current_x++;
			fill_altitude_map(map, current_point);
		}
		while (line[i] && line[i] != ' ')
			i++;
		while (line[i] && line[i] == ' ')
			i++;
	}
	if (map->map_width == 0)
		map->map_width = current_x;
}

void	parsing_opti(t_map *map, int fd)
{
	char	*gnl_res;
	int		y;

	gnl_res = get_next_line(fd);
	y = 0;
	while (gnl_res != NULL)
	{
		create_point_line(map, fd, gnl_res, y);
		free(gnl_res);
		gnl_res = get_next_line(fd);
		y++;
	}
	map->map_height = y;
}

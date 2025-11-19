/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:33:04 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/18 11:29:34 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/ft_printf.h"
#include "../../includes/get_next_line_bonus.h"
#include <stdlib.h>

void	clean_exit(int fd, t_point **lst, char *msg)
{
	ft_dprintf(2, "%s\n", msg);
	clear_point_lst(lst);
	while (get_next_line(fd) != NULL)
		;
	exit(1);
}

void	parsing_opti(t_map *map, int fd)
{
	char	*gnl_res;
	int		i;
	int		current_x;
	int		y;
	t_point	*current_point;

	gnl_res = get_next_line(fd);
	y = 0;
	while (gnl_res != NULL)
	{
		i = 0;
		current_x = 0;
		while (gnl_res[i])
		{
			if (gnl_res[i] != ' ')
			{
				current_point = get_first_point(&gnl_res[i]);
				if (current_point == NULL)
					clean_exit(fd, map->lst, "Malloc error");
				add_point_static_lst(map->lst, current_point, current_x, y);
				current_x++;
			}
			if (current_point && ABS(current_point->altitude) > ABS(map->map_altitude))
				map->map_altitude = current_point->altitude;
			while (gnl_res[i] && gnl_res[i] != ' ')
				i++;
			while (gnl_res[i] && gnl_res[i] == ' ')
				i++;
		}
		free(gnl_res);
		gnl_res = get_next_line(fd);
		y++;
	}
	map->map_width = current_x;
	map->map_height = y;
}

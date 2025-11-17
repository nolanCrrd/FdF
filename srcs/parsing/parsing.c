/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:33:04 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/17 13:22:18 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/libft.h"
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

void	split_clear(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

/**
 * @brief Setup the map structure with all the data in fd
 *
 * @param map Strcture of the map
 * @param fd File descriptor of the map file
 * @return 
 */
int	generate_point_list(t_map *map, int fd)
{
	char	**current_line;
	char	**current_point;
	char	*gnl_res;
	int		current_x;
	int		y;

	gnl_res = get_next_line(fd);
	y = 0;
	while (gnl_res != NULL)
	{
		current_x = 0;
		current_line = ft_split(gnl_res, ' ');
		if (current_line != NULL)
		{
			while (current_line[current_x] != NULL)
			{
				current_point = ft_split(current_line[current_x], ',');
				if (current_point == NULL)
					clean_exit(fd, map->lst, "Malloc failed");
				if (add_point_list(map->lst, current_point, current_x, y))
					clean_exit(fd, map->lst, "Malloc failed");
				current_x++;
				split_clear(current_point);
			}
		}
		if (map->map_width < current_x)
			map->map_width = current_x;
		free(gnl_res);
		gnl_res = get_next_line(fd);
		y++;
		split_clear(current_line);
	}
	map->map_height = y;
	return (0);
}

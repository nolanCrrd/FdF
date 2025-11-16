/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:33:04 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/14 16:13:59 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/libft.h"
#include "../../includes/get_next_line_bonus.h"

/**
 * @brief create a list of point to render in the window,
 * the list is NULL terminated
 * 
 * @param file_path path to the file that contain the map
 * @return t_point* list of point / NULL for errors
 */
t_point	**generate_point_list(char *file_path)
{
	t_point	**list;
	int		map_width;
	int		map_height;
	char	**current_line;
	char	**current_point;
	char	*gnl_res;
	int		fd;
	int		current_x;
	int		y;

	fd = open_file(file_path);
	if (fd < 0)
		return (NULL);
	gnl_res = get_next_line(fd);
	map_width = -1;
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
				{
					// TODO: handle malloc error
					return (NULL);
				}
				if (add_point_list(&list, current_point, current_x, y))
				{
					// TODO: Handle Error
				}
				current_x++;
			}
		}
		if (map_width == -1)
			map_width = current_x;
		else if (map_width != current_x)
		{
			// TODO: Error
			return (NULL);
		}
		gnl_res = get_next_line(fd);
		y++;
	}
	return (list);
}

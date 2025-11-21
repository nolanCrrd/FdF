/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:24:52 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/21 12:06:03 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static float	get_radian(float angle)
{
	return (angle * M_PI / 180);
}

/**
 * @brief Edit all the current point's projection matrice
 *
 * @param current Point to edit
 * @param angle_x Angle x of the map
 * @param angle_y Angle y of the map
 * @param angle_z Angle z of the map
 */
static void	rotate_point(t_point *current, float angle_x,
	float angle_y, float angle_z)
{
	current->proj[1][X] = current->proj[0][0];
	current->proj[1][Y] = current->proj[0][1] * cos(angle_x)
		- current->proj[0][2] * sin(angle_x);
	current->proj[1][Z] = current->proj[0][1] * sin(angle_x)
		+ current->proj[0][2] * cos(angle_x);
	current->proj[2][X] = current->proj[1][X] * cos(angle_y)
		+ current->proj[1][Z] * sin(angle_y);
	current->proj[2][Y] = current->proj[1][Y];
	current->proj[2][Z] = -current->proj[1][X] * sin(angle_y)
		+ current->proj[1][Z] * cos(angle_y);
	current->proj[3][X] = current->proj[2][X] * cos(angle_z)
		- current->proj[2][Y] * sin(angle_z);
	current->proj[3][Y] = current->proj[2][X] * sin(angle_z)
		+ current->proj[2][Y] * cos(angle_z);
	current->proj[3][Z] = current->proj[2][Z];
}

void	update_projection(t_map *map)
{
	int		i;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	t_point	*current;

	angle_x = RAD(map->angle_x);
	angle_y = RAD(map->angle_y);
	angle_z = RAD(map->angle_z);
	i = 0;
	while (map->lst[i])
	{
		current = map->lst[i];
		current->proj[0][X] = (current->x - map->map_width / 2.0f) * 20;
		current->proj[0][Y] = (current->y - map->map_width / 2.0f) * 20;
		current->proj[0][Z] = current->altitude * 20;
		rotate_point(current, angle_x, angle_y, angle_z);
		map->lst[i]->screen_x = map->lst[i]->proj[3][X]
			* map->scaling + map->x_offset;
		map->lst[i]->screen_y = map->lst[i]->proj[3][Y]
			* map->scaling + map->y_offset;
		i++;
	}
}

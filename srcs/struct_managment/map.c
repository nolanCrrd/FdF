/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:13:42 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/21 11:39:25 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	switch_map_color(t_map *map)
{
	int				i;
	unsigned long	color_tmp;

	i = 0;
	while (map->lst[i])
	{
		color_tmp = map->lst[i]->color;
		map->lst[i]->color = map->lst[i]->second_color;
		map->lst[i]->second_color = color_tmp;
		i++;
	}
}

void	map_fill_relief_color(t_map *map)
{
	int	altitude_delta;
	int	altitude_med;
	int	i;

	altitude_delta = map->map_max_altitude - map->map_min_altitude;
	i = 0;
	altitude_med = (map->map_max_altitude + map->map_min_altitude) / 3;
	while (map->lst[i])
	{
		if (map->lst[i]->altitude <= 0)
		{
			map->lst[i]->second_color = get_color_smooth(ZERO_COLOR, MIN_COLOR,
					ABS(map->lst[i]->altitude),
					ABS(map->map_min_altitude) - ABS(altitude_delta) * 0.15);
		}
		else
		{
			map->lst[i]->second_color = get_color_smooth(ZERO_COLOR, MAX_COLOR,
					map->lst[i]->altitude,
					map->map_max_altitude - altitude_delta * 0.15);
		}
		i++;
	}
}

void	map_init(t_map *map)
{
	map->map_width = 0;
	map->map_height = 0;
	map->map_max_altitude = 0;
	map->map_min_altitude = 0;
	map->scaling = 0.1;
	map->angle_z = 30;
	map->angle_y = -35;
	map->angle_x = 45;
	map->x_offset = WIN_W / 2;
	map->y_offset = WIN_H / 2;
}

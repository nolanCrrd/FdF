/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:24:52 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/16 22:33:55 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	tranform_isometric(t_map *map)
{
	int	i;
	float	new_x;
	float	new_y;
	float	altitude;
	int		scale;
	int		scale_z;
	float	iso_angle;

	i = 0;
	scale = 20;
	iso_angle = map->eye_height * M_PI / 180;
	while (map->lst && map->lst[i])
	{
		new_x = (float)(map->lst[i]->x - map->lst[i]->y);
		new_y = (float)(map->lst[i]->x + map->lst[i]->y);
		altitude = map->lst[i]->altitude;
		new_x = new_x * cos(iso_angle) * scale;
		new_y = new_y * sin(iso_angle) * scale - altitude * map->z_scaling;
		new_x +=  WIN_W / 2 - ((map->map_width / 2.0 - map->map_height / 2.0) * cos(iso_angle) * scale) ;
		new_y += WIN_H / 2 - ((map->map_width / 2.0 + map->map_height / 2.0) * sin(iso_angle) * scale);
		map->lst[i]->proj_x = round(new_x);
		map->lst[i]->proj_y = round(new_y);
		map->lst[i]->screen_x = map->lst[i]->proj_x;
		map->lst[i]->screen_y = map->lst[i]->proj_y;
		i++;
	}
}
